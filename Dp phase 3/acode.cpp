//https://www.spoj.com/problems/ACODE/
// https://atcoder.jp/contests/dp/tasks/dp_b
#include <bits/stdc++.h>
using namespace std;
using ll = long long ;
int  rec(int level, int n,int ist,vector<int>&arr, vector<vector<int>>&dp){
    // prunig 
    
    if(ist==1&&level==n){
        if(arr[level]<=6) return 1;
        else return 2;
    }
    if(ist==0&&level==n) return 1;
    if (dp[level][ist]!=-1) return dp[level][ist];
    ll ans=0;
    if(ist==0){
        if(arr[level]>=1&&arr[level]<=2) ans+=rec(level+1,n,1,arr,dp);
        
         ans+=rec(level+1,n,0,arr,dp);
          
    }
    if(ist==1){
          if(arr[level]<=6) ans+=rec(level+1,n,0,arr,dp);
    }
    


return dp[level][ist]=ans;

}
void solve() {
    while(1){
        ll temp;
        cin>>temp;
    if(temp==0) break;
    vector<int>arr;
    
    // memset(dp,-1,sizeof(dp));/
      
   while(temp>0)   {  
        arr.push_back(temp%10);
        temp/=10;
    }
    reverse(arr.begin(),arr.end());
    vector<vector<int>>dp;
    //for(int i=0;i<arr.size();i++) cout<<arr[i]<<endl;
    dp.assign(arr.size(),vector<int>(2,-1));
   cout<<rec(0, arr.size()-1,0, arr, dp)<<endl;
    }    

}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}