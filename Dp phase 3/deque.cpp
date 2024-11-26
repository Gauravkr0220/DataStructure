
// Write your code here

// you can set your Template at profile settings [https://maang.in/profile/edit-profile]
#include <bits/stdc++.h>
using namespace std;
using ll =long long;
int n,m;
vector<ll>vec;
ll dp[3005][3005][2];
ll rec(int i,int j,int k){
    if(i==j&& k==0) return vec[i];
    if(i==j&& k==1) return -vec[i];
    
   
    if(dp[i][j][k]!=-1) return dp[i][j][k];
    ll ans=INT_MIN;
    if(k==0){
        ans=max(rec(i+1,j,1)+vec[i],rec(i,j-1,1)+vec[j]);
    }
     if(k==1){
        ans=min(rec(i+1,j,0)-vec[i],rec(i,j-1,0)-vec[j]);
    }

    return dp[i][j][k]=ans;

}
void solve() {
   cin>>n;
   vec.resize(n);
   memset(dp,-1,sizeof(dp));
   for(int i=0;i<n;i++){
    cin>>vec[i];
   }
   cout<<rec(0,n-1,0)<<endl;
       
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
        solve();
    
    return 0;
}