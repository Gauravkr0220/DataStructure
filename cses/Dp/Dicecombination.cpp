#include<bits/stdc++.h>
using namespace std;
#define int long long
int dp[1000005];
const int mod = 1e9 + 7;
int rec(int n)
{
    if(n<0) return 0;
    if(n==0) return 1;
    if(dp[n]!=-1) return dp[n];
    int ans=0;
    for(int i=1;i<=6;i++)
    {
        ans=(ans%mod+rec(n-i)%mod)%mod;
    }
    return dp[n]=ans;
}
void solve()
{
    int n;
    memset(dp, -1, sizeof(dp));
    cin>>n;
    int ans=rec(n);
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}