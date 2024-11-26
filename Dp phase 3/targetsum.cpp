// // x time and k slot
// #include <bits/stdc++.h>
// int n,t;
// int x[105];
// using namespace std;
// int dp[105][10040];
// int rec(int level,int taken){
//     if(taken>t) return 0;
//     if(level==n+1){
//         if (taken==t) return 1;
//         else return 0;
//     }
// if(dp[level][taken]!=-1) return dp[level][taken];
// int ans=0;
// if(rec(level+1,taken)==1) ans=1;
// else if(rec(level+1,taken+x[level])) ans=1
// dp[level][taken]=ans;
// return ans;
// }
// void solve() {
//     cin>>n;
//    for(int i=1;i<n;i++){
//     cin>>x[i];
//    }
//    memset(dp,-1,sizeof(dp));
//    cin>>t;
//    cout<<rec(1,0);
// }

// signed main() {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     solve();
//     return 0;
// }

#include <bits/stdc++.h>
int n, t, q;
int x[105];
using namespace std;
int dp[105][10040];
int rec(int level, int left)
{
    if (left < 0)
        return 0;
    if (level == n + 1)
    {
        if (left == t)
            return 1;
        else
            return 0;
    }
    if (dp[level][left] != -1)
        return dp[level][left];
    int ans = 0;
    if (rec(level + 1, left) == 1)
        ans = 1;
    else if (rec(level + 1, left - x[level]))
        ans = 1 dp[level][taken] = ans;
    return ans;
}
void solve()
{
    cin >> n >> q;
    for (int i = 1; i < n; i++)
    {
        cin >> x[i];
    }
    memset(dp, -1, sizeof(dp));
    while (q--)
    {
        cin >> t;
        cout << rec(1, t);
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}