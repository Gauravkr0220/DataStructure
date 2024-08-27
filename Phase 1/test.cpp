#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
#define fr(i, a, b) for (int i = a; i < b; ++i)




void solve() {
   ll n,s,m;
   cin>>n>>s>>m;
 
   bool flag=false;
   ll a,b=0;
   while(n--){
    
    cin>>a;
    if(a-b>=s){
        flag=true;
    }
    ll l;
    cin>>l;
    b=l;
   }
  
  
   if(m-b>=s) flag=true;
   if(flag)
   cout<<"YES"<<endl;
   else
   cout<<"NO"<<endl;
   
   
   
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t ;
    cin >> t;
    while (t--) solve();

    return 0;
}