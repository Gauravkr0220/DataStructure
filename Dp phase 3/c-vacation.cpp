#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;
vector<ll> a, b, c;
ll dp[100500][2][2][2];

ll rec(ll i, ll ai, ll bi, ll ci) {
    // Base case
    if (i == n) {
        return 0;
    }
    // Cache check
    if (dp[i][ai][bi][ci] != -1) {
        return dp[i][ai][bi][ci];
    }

    ll ans = 0;
    // Transition logic
    if (ai == 0) {
        ans = rec(i + 1, 1, 0, 0) + a[i];
    }
    if (bi == 0) {
        ans = max(ans, rec(i + 1, 0, 1, 0) + b[i]);
    }
    if (ci == 0) {
        ans = max(ans, rec(i + 1, 0, 0, 1) + c[i]);
    }

    // Save and return
    return dp[i][ai][bi][ci] = ans;
}

void solve() {
    cin >> n;

    a.resize(n);
    b.resize(n);
    c.resize(n);
    memset(dp, -1, sizeof(dp));  // Initialize dp table to -1

    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }

    ll ans = rec(0, 0, 0, 0);  // Start the recursion with ai=0, bi=0, ci=0
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}
