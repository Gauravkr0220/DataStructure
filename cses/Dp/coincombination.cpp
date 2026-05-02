#include<bits/stdc++.h>
using namespace std;
int dp[1000005];
vector<int>coin;
const int mod=1e9+7;
int rec(int n)
{
    if(n<0) return 0;
    if(n==0) return 1;
    if(dp[n]!=-1) return dp[n];
    int ans=0;
    for(int i=0;i<coin.size();i++)
    {
        ans=(ans%mod+rec(n-coin[i])%mod)%mod;
    }
    return dp[n]=ans;
}
void solve()
{
    int n,x;
    cin>>n>>x;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++)
    {
        int g;
        cin>>g;
        coin.push_back(g);
    }
    int ans= rec(x);
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