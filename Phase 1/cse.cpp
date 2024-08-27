
// Write your code here

// you can set your Template at profile settings [https://maang.in/profile/edit-profile]
#include <bits/stdc++.h>
using namespace std;
using ll= long long;

void solve() {
   int n;
   cin>>n;
   ll arr[n];
   for(int i=0;i<n;i++){
    cin>>arr[i];
   } 
   ll ans=0;
   ll lar=arr[0];
   for(int i=1;i<n;i++){
      if(arr[i]<lar){
        ans+=lar-arr[i];
      }
      else {
        lar=arr[i];
      }
   }
   cout<<ans<<'\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
        solve();
  
    return 0;
}