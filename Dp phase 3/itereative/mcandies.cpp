// https://atcoder.jp/contests/dp/tasks/dp_m

#include <bits/stdc++.h>
using namespace std;
using ll = long long ;
const ll mod =1e9+7;
void solve(){
   int n,k;
   cin>>n>>k;
   vector<int>vec;
   for(int i=0;i<n;i++){
    int g;
    cin>>g;
    vec.push_back(g);
   }
   vector<vector<ll>> dp(n + 1, vector<ll>(k + 1, 0));
   for(int l=n;l>=0;l--){
    for(int left=0;left<=k;left++){
        if(l==n){
            if(left==0) dp[l][left]=1;
            else dp[l][left]=0;
            continue;
        }
        dp[l][left]=dp[l+1][left];
        if(left-vec[l]-1>=0)
        dp[l][left]-=dp[l+1][left-vec[l]-1];
        

    }
    for(int left=1;left<=k;left++){
        dp[l][left]=(dp[l][left]%mod+dp[l][left-1]%mod)%mod;
    }
   }
   if(k>0)
   cout<<dp[0][k]-dp[0][k-1]<<endl;
   else{
    cout<<dp[0][k]<<endl;

   }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}