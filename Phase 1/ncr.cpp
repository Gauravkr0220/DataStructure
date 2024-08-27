
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;

vector<int> brr, arr;

int binPow(int b, int a, int mod) {
    int ans = 1;
    while (a > 0) {
        if (a % 2 == 1) {
            ans = (ans * b) % mod;
        }
        b = (b * b) % mod;
        a /= 2;
    }
    return ans;
}

void solvebrrs(int maxi) {
    brr.resize(maxi + 1);
    arr.resize(maxi + 1);
    brr[0] = 1;
    for (int i = 1; i <= maxi; ++i) {
        brr[i] = brr[i - 1] * i % mod;
    }
    arr[maxi] = binPow(brr[maxi], mod - 2, mod);
    for (int i = maxi - 1; i >= 0; --i) {
        arr[i] = arr[i + 1] * (i + 1) % mod;
    }
}

int binomial(int n, int k) {
    if (k > n || k < 0) return 0;
    return brr[n] * arr[k] % mod * arr[n - k] % mod;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t_=1;
    cin >> t_;

    solvebrrs(200000);

    while (t_--) {
        int n, k;
        cin >> n >> k;

        vector<int> v(n);
        int countOne = 0;
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
            if (v[i] == 1) countOne++;
        }

        int countZero = n - countOne;

        int ans = 0;

    for (int i = (k + 1) / 2; i <= min(countOne, k); ++i) {
            int j = k - i;
            if (j <= countZero) {
                ans = (ans + binomial(countOne, i) * binomial(countZero, j)) % mod;
            }
        }

        cout << ans << endl;
    }

    return 0;
}