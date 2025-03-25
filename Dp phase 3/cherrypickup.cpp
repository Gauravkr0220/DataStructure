#include <bits/stdc++.h>

using namespace std;
int n,m;
int arr[1010][1010];
int dx[]={0,1};
int dy[]={1,0};
int dp[51][51][51];
int check(int a,int b){
    if(a>=0&&a<n&&b>=0&&b<m) return 1;
    return 0;
}
int rec(int i,int j,int a){ // State space reduction removing b
    int b=i+j-a;
    cout<<i<<" "<<j<<" "<<a<<" "<<b<<endl;
    //pruning
    // basecase
    if(i==n-1&&j==m-1){
        return arr[i][j];
    }
    //cache check
    if(dp[i][j][a]!=-1)
    return dp[i][j][a];
    // transition
    int initial_cost =arr[i][j]+arr[a][b];
    if(a==i&&b==j){
        initial_cost=arr[i][j];
    }
    int ans=0;
    for(int k1=0;k1<2;k1++){
        for(int k2=0;k2<2;k2++){
            int ni,nj,na,nb;
            ni=i+dx[k1];
            nj=j+dy[k1];
            na=a+dx[k2];
            nb=b+dy[k2];
            if(check(ni,nj)&&check(na,nb)){
                ans=max(ans,initial_cost+rec(ni,nj,na));
            }
        }
    }
    return dp[i][j][a]=ans;
}
void solve() {
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,0,0)<<endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}