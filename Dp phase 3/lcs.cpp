// x time and k slot 
#include <bits/stdc++.h>
using namespace std;
using ll =long long;
ll n,m;
string s,l,ans;
ll dp[3003][3003];
int done[3003][3003];

ll rec(ll i,ll j){
    // prunig 
    
    // base case
    if(i==n||m==j) return 0;
    // cache check
    if(dp[i][j]!=-1) return dp[i][j];
    // compute
    int ans=-1e9;
    if(ans<rec(i+1,j)){
        ans= rec(i+1,j);
        done[i][j]=0;
    }
   if(ans<rec(i,j+1)){
        ans= rec(i,j+1);
        done[i][j]=1;
    }
    if(s[i]==l[j]&&ans<rec(i+1,j+1)+1){
        ans= rec(i+1,j+1)+1;
        done[i][j]=2;
    }
    // save and return 
return dp[i][j]=ans;

}
void generator(int i,int j){
    if(i==n&&j==m) return ;
    if(done[i][j]==0){
        generator(i+1,j);
    }
    else if(done[i][j]==1){
        generator(i,j+1);
    }
    else if(done[i][j]==2){
        cout<<s[i];
        generator(i+1,j+1);
    }
}
void solve() {
    memset(dp,-1,sizeof(dp));
    cin>>s>>l;
    n=s.size(),m=l.size();
   int c=rec(0,0);
   generator(0,0);
    
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}