#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 





void solve() {
  ll n,m;
  cin>>n>>m;
  vector<vector<ll>vec;
  vec.resize(n+1);
  for(int i=1;i<=n;i++){
    ll l;
    cin>>l;
    vec[i].resize(l);
    for(int j=0;j<l;j++){
      cin>>vec[i][j];
    }
    sort(vec[i].begin(),vec.end());
  }
  vector<ll>ch;
 for(int i=1;i<=n;i++){
   bool flag =
    for(int j=0;j<l;j++){
      cin>>vec[i][j];
    }
   
  }

  
   
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t ;
    cin >> t;
    while (t--) solve();

    return 0;
}