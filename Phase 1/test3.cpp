#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int check(ll x, double avg, ll n, const vector<ll>& vec) {
    if ((upper_bound(vec.begin(), vec.end(), (avg + double(x) / n)/2) - vec.begin()) >= n / 2 + 1)
        return 1;
    else
        return 0;
}

void solve() {
    int n;
    cin >> n;
    vector<ll> vec(n + 1); // Create a vector of size n + 1
    vec[0] = 0;
    double sum = 0;

    for (int i = 1; i <= n; i++) {
        int g;
        cin >> g;
        vec[i] = g;
        sum += g;
    }

    if (n == 1 || n == 2) {
        cout << -1 << endl;
        return;
    }

    double avg = sum / n;
    sort(vec.begin(), vec.end());

    ll lo = 0, hi = 2e18;
    ll ans = -1; // Declare 'ans' as ll to handle large values

    while (lo <= hi) {
        ll mid = lo + (hi - lo) / 2;
        if (check(mid, avg, n, vec)) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
