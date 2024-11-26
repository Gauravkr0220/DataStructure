// x time and k slot 
#include <bits/stdc++.h>
using namespace std;
using ll =long long;
ll n;
ll arr[10100];
ll dp[100100];
ll rec(ll level){
    // prunig 
    if(level<0) return 0;
    // base case

    // cache check
    if(dp[level]!=-1) return dp[level];
    // compute
    int ans=1;
    for(int prev_taken=0;prev_taken<level;prev_taken++){
        if(arr[prev_taken]<arr[level]){
            ans=max(ans,1+rec(prev_taken));
        }
    }
    // save and return 
return dp[level]=ans;

}
void solve() {
    cin>>n;
    memset(dp,-1,sizeof(dp));
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int best=0;
    for (int i = 0; i < n; i++)
    {
        best=max(best,rec(i));
    }
     cout<<best<<endl;
    
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}