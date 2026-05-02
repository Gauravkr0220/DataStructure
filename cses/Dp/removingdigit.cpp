#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
int dp[1000006];
int rec(int n)
{
    if(n==0) return 0;
    if(n<0) return 1e9;
    if(dp[n]!=-1) return dp[n];
    int ans=1e9;
    int x=n;
    while(x)
    {   int d=x%10;
        if(d!=0)
        ans=min(ans,rec(n-d)+1);
        x/=10;
    }
    return dp[n]=ans;
}
void solve()
{
    int n;
    cin>>n;
    memset(dp,-1,sizeof(dp));
    cout<<rec(n)<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}