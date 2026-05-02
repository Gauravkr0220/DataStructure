#include <bits/stdc++.h>
using namespace std;
#define int long long

int n;
int dp[200005];
vector<int> start, endd, cost;

int rec(int level) {
    if (level == n) return 0;
    if (dp[level] != -1) return dp[level];

    
    int ans = rec(level + 1);

    int next = upper_bound(start.begin(), start.end(), endd[level]) - start.begin();
    ans = max(ans, rec(next) + cost[level]);

    return dp[level] = ans;
}

void solve() {
    cin >> n;
    vector<vector<int>> jobs(n, vector<int>(3));

    for (int i = 0; i < n; ++i) {
        cin >> jobs[i][0] >> jobs[i][1] >> jobs[i][2];  
    }
    sort(jobs.begin(), jobs.end());

    for (int i = 0; i < n; ++i) {
        start.push_back(jobs[i][0]);
        endd.push_back(jobs[i][1]);
        cost.push_back(jobs[i][2]);
    }

    memset(dp, -1, sizeof(dp));
    cout << rec(0) << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
