#include<bits/stdc++.h>
using namespace std;
int dp[101][100005];
int n;
vector<int>vec;
int rec(int level,int sum)
{
    if(level==n)
    {
        if(sum==0) return 1;
        else  return 0;
    }
    if(dp[level][sum]!=-1) return dp[level][sum];
    int ans=0;
    ans+=rec(level+1,sum);
    if(vec[level]<=sum) ans+=rec(level+1,sum-vec[level]);
    return ans>0 ? dp[level][sum]=1: dp[level][sum]=0;
}
void solve()
{
    memset(dp,-1,sizeof(dp));
    cin>>n;
    int sum=0;
    int mini=1e9;
    for(int i=0;i<n;i++)
    {
        int g;
        cin>>g;
        sum+=g;
        mini=min(mini,g);
        vec.push_back(g);
    }
    vector<int>ans;

    for(int i=mini;i<=sum;i++)
    {
        if(rec(0,i)) ans.push_back(i);
    }
    cout<<ans.size()<<endl;
    for(auto v:ans) cout<<v<<" ";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}