#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
int w[1000];
int v[3000];
int dp[3003][3003];
int rec(int i,int x){
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
  int ans=rec(i+1,x);
  if(w[i<=x]){
    ans=max(ans,v[i]+rec(i+1,x-w[i]));
  }
  //save and return
  return dp[i][x]=ans;
}
void solve()
{ 
cin>>n;
  memset(dp,-1,sizeof(dp));
for (int i = 0; i < n; i++)
{
    cin>>w[i];

}
for (int i = 0; i < n; i++)
{
    cin>>v[i];
}
int W;
cin>>W;
int ans=rec(0,W);
  
  
}

signed main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--)

    solve();

  return 0;
}