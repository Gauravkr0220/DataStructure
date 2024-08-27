#include <bits/stdc++.h>
using namespace std;
void solve()
{
 int s,k;
 cin>>k>>s;
 int ans=0;
 for(int x=0;x<=k;x++){
  for(int y=0;y<=k;y++){
    if((s-k)<=(x+y)&&(x+y)<=s){
      ans++;
    }
  }
 }
 cout<<ans;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    

             solve();
   
    return 0;
}