// https://atcoder.jp/contests/dp/tasks/dp_b
//but it is optimized solution as we donot need dp for this question 
// we can take all k minmimun ans make subarray with them by expand left right
#include <bits/stdc++.h>
using namespace std;
using ll = int ;
// ll n,k;
// ll arr[10100];
// ll dp[10100];
int  rec(int i, int x,vector<int>&arr, vector<vector<int>>&dp){
    // prunig 
    if(x<0) return 1e9;
    // base case
     if( i==-1) {
        if(x==0){
            return 0;
        }
        else{
            return 1e9;// as we are finding minimum value
        }
     }
    // cache check
  if(dp[i][x]!=-1) return dp[i][x];
    // compute
    ll ans=INT_MAX;
    int min_seen=arr[i];
    for(int j=i-1;j>=-1;j--){
           ans=min(ans,rec(j,x-1,arr,dp)+min_seen);
           min_seen=min(min_seen,arr[j]);
    }
    // save and return 

return dp[i][x]=ans;

}
void solve() {
    int n,k;
    cin>>n>>k;
    vector<int>arr(n);
    
    
      
    for (int i = 0; i < n; i++)
    {         
        cin>>arr[i];
    }

    vector<vector<int>>dp;
    dp.assign(n+1,vector<int>(k+1,-1));
   cout<<rec(n-1, k, arr, dp);
    
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}