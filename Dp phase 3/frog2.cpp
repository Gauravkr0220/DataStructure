// https://atcoder.jp/contests/dp/tasks/dp_b
#include <bits/stdc++.h>
using namespace std;
using ll = int ;
// ll n,k;
// ll arr[10100];
// ll dp[10100];
int  rec(int level, int k,vector<int>&arr, vector<int>&dp){
    // prunig 
    
    // base case
     if( level <= 0) return 0;
    // cache check
  if(dp[level]!=-1) return dp[level];
    // compute
    ll ans=INT_MAX;
    for(int i=1;i<=k;i++){
        if(level-i>=0){
            int temp = rec(level-i, k,arr, dp)+abs(arr[level-i]-arr[level]);
            ans=min(ans,temp);
    }
    }
    // save and return 

return dp[level]=ans;

}
void solve() {
    int n,k;
    cin>>n>>k;
    vector<int>arr(n);
    
    // memset(dp,-1,sizeof(dp));/
      
    for (int i = 0; i < n; i++)
    {         
        cin>>arr[i];
    }

    vector<int>dp(n, -1);
   cout<<rec(n-1, k, arr, dp);
    
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}