#include<bits/stdc++.h>
using namespace std;

int n,m;
int dp[505][505];
int rec(int i, int j) {
    if (i == j) return 0; 
    if (dp[i][j] != -1) return dp[i][j];

    int ans = 1e9;

    
    for (int k = 1; k < i; k++) {
        ans = min(ans, rec(k, j) + rec(i - k, j) + 1);
    }

   
    for (int k = 1; k < j; k++) {
        ans = min(ans, rec(i, k) + rec(i, j - k) + 1);
    }

    return dp[i][j] = ans;
}
void solve()
{
    cin>>n>>m;
    memset(dp, -1, sizeof(dp));
    int ans=rec(n,m);
    cout<<ans<<endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    
    return 0;
}