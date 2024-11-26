// x time and k slot 
#include <bits/stdc++.h>
using namespace std;
using ll =long long;
ll n,m;
ll arr[1010][1010];
ll dp[1010][1010];
bool done[1001][1001];
ll rec(ll r,ll c){
    // prunig 
    
    // base case
    if(r==0&&c==0) return arr[0][0];
    // cache check
    if(done[r][c]) return dp[r][c];
    // compute
    int ans=-1e9;
    if(r!=0){
        ans= max(ans,rec(r-1,c)+arr[r][c]);
    }
    if(c!=0){
           ans= max(ans,rec(r,c-1)+arr[r][c]);
    }
    // save and return 
    done[r][c]=1;// it will ensure that when -1 again came in dp[r][c]it will not recompute
return dp[r][c]=ans;

}
void solve() {
    cin>>n>>m;
    memset(dp,-1,sizeof(dp));
        memset(done,0,sizeof(done));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
                  
        cin>>arr[i][j];
        }
  
    }
   cout<<rec(n-1,m-1);
    
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}