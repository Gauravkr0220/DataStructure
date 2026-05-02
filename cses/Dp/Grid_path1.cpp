#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int n;
vector<vector<char>>grid;
int dp[1005][1005];
int rec(int i,int j)
{
    if(i<0||j<0) return 0;
    if(i==0&&j==0)
    {
        if(grid[i][j]=='.') return 1;
        else return 0;
    }
    if(dp[i][j]!=-1) return dp[i][j];
    int ans=0;
    if(grid[i][j]=='.')
    {
        ans=(rec(i-1,j)%mod+rec(i,j-1)%mod)%mod;
    }
    return dp[i][j]=ans;
}
void solve()
{
    cin>>n;
    grid.resize(n+1);
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    {
        char c;
        cin>>c;
        grid[i].push_back(c);
    }
    memset(dp,-1,sizeof(dp));
    int ans=rec(n-1,n-1);
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