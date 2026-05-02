#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
int dp[1000001][101];
vector<int> coin;

int rec(int n, int level) {
    if (n < 0) return 0;
    if (n == 0) return 1;
    if (level >= coin.size()) return 0;
    if (dp[n][level] != -1) return dp[n][level];
    
    int ans = rec(n, level + 1); // Don't use this coin
    ans = (ans + rec(n - coin[level], level)) % mod;
    
    return dp[n][level] = ans;
}

void solve() {
    int n, x;
    cin >> n >> x;

    // Clear previous coins
    coin.clear();

    for (int i = 0; i < n; i++) {
        int g;
        cin >> g;
        coin.push_back(g);
    }

    // Only init up to x and n
    for (int i = 0; i <= x; i++)
        for (int j = 0; j < n; j++)
            dp[i][j] = -1;

    int ans = rec(x, 0);
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
