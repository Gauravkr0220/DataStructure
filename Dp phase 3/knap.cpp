#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n;
int W;
vector<ll>w;
vector<ll>v;
ll dp[105][100500];
ll rec(ll i,ll x){
  //prunig
  //base case
  if(i==n){
    return 0;
  }
  //cache check
if(dp[i][x]!=-1){
    return dp[i][x];
}
  //transition
  ll ans=rec(i+1,x);
  if(w[i]<=x){
    ans=max(ans,v[i]+rec(i+1,x-w[i]));
  }
  //save and return
 
  return dp[i][x]=ans;
}

//print solution
// vector<int>solution;
// void generation(int i,int x){
//         if(i==n){
//     return 0;
//   }
//   else{
//     int dontake=rec(i+1,x);
//     if(w[i]<=x){
//         int take=rec(i+1,x-w[i])+v[i];
//         if(dontake>take){
//             generation(i+1,x);
//         }
//         else{
//             solution.push_back(i);
//             generation(i+1,x-w[i]);
//         }
//     }
//     else{
//         generation(i+1,x);
//     }
//   }
// }
void solve()
{ 
cin>>n;
cin>>W;
w.resize(n);
v.resize(n);
  memset(dp,-1,sizeof(dp));
for (int i = 0; i < n; i++)
{
    cin>>w[i]>>v[i];

}
ll ans=rec(0,W);
 cout<<ans<<endl;
  
}

signed main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);


    solve();

  return 0;
}