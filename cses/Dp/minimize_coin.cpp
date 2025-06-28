#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
int dp[1000005];
vector<int>coins;
int rec(int n)
{
    if(n < 0) return 1e9; // impossible case
    if(n == 0) return 0; // no coins needed
    if(dp[n] != -1) return dp[n];
    
    int ans = 1e9;
    for(int coin : coins)
    {
        ans = min(ans, rec(n - coin) + 1);
    }
    
    return dp[n] = ans;
}
void solve()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++) {
        int x;
        cin>>x;
        coins.push_back(x);
    }
    memset(dp, -1, sizeof(dp));
    int ans=rec(m);
    if(ans>=1e9) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}