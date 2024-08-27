#include <bits/stdc++.h>
using namespace std;


void solve() {
    int m;cin>>m;
  int *a[m];
  for (int i=0;i<m;i++){
    a[i]=new int[i+1];
  }
  int ct=0;
  
  for (int i=0;i<m;i++){
    for (int j=0;j<=i;j++){
        
        a[i][j]=ct++;}}
        for (int i=0;i<m;i++){
    for (int j=0;j<=i;j++){
       cout<< a[i][j]<<' ';}
       cout<<endl;}

   
   
   
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    
        solve();
   
    return 0;
}
