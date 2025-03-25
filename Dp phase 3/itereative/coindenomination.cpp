
#include <bits/stdc++.h>
using namespace std;
using ll = long long ;
int dp[1010][1010];

void solve() {
   int n,m;
    int x[n];
    for(int i=;i<n;i++){
        cin>>x[i];
    }
    int dp[n+1][m+1];
    for(int l=n;l>=0;i-- ){
      for(int s=0;<=m;s++){
        if(l==n){
            if(s==0) dp[l][s]=1;
            else dp[l][s]=0;
        }
         int dp[l][s]=0;
         if(dp[l+1][s]){
            dp[l][s]==1;
         }
        if(s>=x[l]&&dp[l][s-x[l]]){
            dp[l][s]==1;
        }

      }  
    }
     cout<<dp[0][m]<<endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}