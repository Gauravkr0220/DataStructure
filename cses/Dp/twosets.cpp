#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 1e9 + 7;
int n;
int dp[505][125005];  

int rec(int i, int sum) {
    if (i == n + 1) {
        return sum == (n * (n + 1)) / 4 ? 1 : 0;
    }
    if (dp[i][sum] != -1) return dp[i][sum];

    int ans = rec(i + 1, sum) % mod;         
    ans = (ans + rec(i + 1, sum + i)) % mod; 

    return dp[i][sum] = ans;
}

int modinv(int a, int m) {

    int res = 1, b = m - 2;
    while (b) {
        if (b & 1) res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}

void solve() {
    cin >> n;

    int total = n * (n + 1) / 2;
    if (total % 2 != 0) {
        cout << 0 << "\n";  
        return;
    }

    memset(dp, -1, sizeof(dp));
    int ways = rec(1, 0);

    
    int inv2 = modinv(2, mod);
    ways = (ways * inv2) % mod;

    cout << ways << "\n";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
