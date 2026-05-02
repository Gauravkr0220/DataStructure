#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
const int x = 1e6 + 5;
int dp[x][2];

int rec(int level, int state) {
    if (level == 1) return 1;
    if (dp[level][state] != -1) return dp[level][state];
    
    int ans = 0;
    if (state == 1) {
        ans = (2LL * rec(level - 1, state) % mod + rec(level - 1, 0)) % mod;
    } else {
        ans = (4LL * rec(level - 1, 0) % mod + rec(level - 1, 1)) % mod;
    }
    
    return dp[level][state] = ans;
}

void solve() {
    int n;
    cin >> n;
    int ans = (rec(n, 0) + rec(n, 1)) % mod;
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // Initialize dp array
    for (int i = 0; i < x; i++) {
        dp[i][0] = -1;
        dp[i][1] = -1;
    }

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
