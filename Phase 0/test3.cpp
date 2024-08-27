
// Write your code here

// you can set your Template at profile settings [https://maang.in/profile/edit-profile]
#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin>>n;
    int arr1[n],arr2[n-1],arr3[n-2];
    for(int i=0;i<n;i++){
        cin>>arr1[i];
    }
    for(int i=0;i<n-1;i++){
        cin>>arr2[i];
    }
    for(int i=0;i<n-2;i++){
        cin>>arr3[i];
    }
    sort(arr1,arr1+n);
    sort(arr2,arr2+n-1);
    sort(arr3,arr3+n-2);
    for(int i=0;i<n;i++){
        cout<<arr1[i]<<' ';
    }
    cout<<endl;
    for(int i=0;i<n-1;i++){
        cout<<arr2[i];
    }
     cout<<endl;
    for(int i=0;i<n-2;i++){
        cout<<arr3[i];
    }
     cout<<endl;
    int b=arr1[n-1],c=arr2[n-2];
    for(int i=0;i<n-1;i++){
        if(arr1[i]!=arr2[i]) {b=arr1[i]; break;}
    }
    for(int i=0;i<n-2;i++){
        if(arr2[i]!=arr3[i]) {c=arr2[i];break;}
    }
    cout<<b<<' '<<c<<endl;
   
    
    
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}