#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int dp[100005][101];
int n,m;
vector<int>vec;
int rec(int level,int prev)
{
    if(level==n) return 1;
    if(dp[level][prev]!=-1) return dp[level][prev];
    int ans=0;
    if(vec[level]==0)
    {
        if(prev+1>0&& prev+1<=m)
        {
            ans=(ans%mod+rec(level+1,prev+1)%mod)%mod;
        }
        if(prev-1>0&& prev-1<=m)
        {
            ans=(ans%mod+rec(level+1,prev-1)%mod)%mod;
        }
        if(prev>0&& prev<=m)
        {
            ans=(ans%mod+rec(level+1,prev)%mod)%mod;
        }
    }
    else
    {
        if(abs(vec[level]-prev)<=1)
        {
            ans=(ans%mod+rec(level+1,vec[level])%mod)%mod;
        }
        else
        {
            return dp[level][prev]=ans; // Invalid value for vec[level]
        }
    }
      return dp[level][prev]=ans;
}
void solve()
{
     memset(dp,-1,sizeof(dp));
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        int g;
        cin>>g;
        vec.push_back(g);
    }
    int ans=0;
    if(vec[0]==0){
        for(int i=1;i<=m;i++)
        {
            ans=(ans%mod+rec(1,i)%mod)%mod;
        }
    }
    else
     ans=rec(0,vec[0]);
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