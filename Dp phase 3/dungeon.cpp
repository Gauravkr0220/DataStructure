
// Write your code here

// you can set your Template at profile settings [https://maang.in/profile/edit-profile]
#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<vector<int>>vec;
int dp[205][205];
int rec(int i,int j){
    if(i<0||j<0) return 1e9;
    
    if(i==0&& j==0) return vec[i][j];
    if(dp[i][j]!=-1) return dp[i][j];
    int ans=INT_MAX;
    
    ans=min(rec(i-1,j),rec(i,j-1))+vec[i][j];
    return dp[i][j]=ans;

}
void solve() {
   cin>>n>>m;
   vec.resize(n);
   memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++)
    for(int j=0;j<m;j++){
        int g;
        cin>>g;
        vec[i].push_back(g);
    }
    
    cout<<abs(rec(n-1,m-1))+1<<endl;
    for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        cout<<dp[i][j]<<" ";
    }
    cout<<endl;}   
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}