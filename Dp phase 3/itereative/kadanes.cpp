
#include <bits/stdc++.h>
using namespace std;
using ll = long long ;
void solve(){
    int n;
     cin>>n;
     int arr[n];
     for(int i=0;i<n;i++ ){
        cin>>arr[i];
     }
     long long dp[n];
     long long ans=-1e9;
    //  for(int i=0;i<n;i++){
    //     if(i==0){
    //         dp[i]=arr[i];   
    //     }
    //     else{
    //         dp[i]=max(dp[i-1]+arr[i],arr[i]);
    //     }
    //     ans=max(ans,dp[i]);
    //  }

    // optimized case
    long long last=-1e9;
    for(int i=0;i<n;i++){
        if(i==0){
            last=arr[i];   
        }
        else{
            last=max(last+arr[i],arr[i]);
        }
        ans=max(ans,last);
     }
     cout<<ans<<endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}