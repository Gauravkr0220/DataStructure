#include<bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    cin>>s;
     int n=s.size();
     vector<int>dp(n,0);
     vector<int>last(26,-1);
     vector<int>sum(n+1,0);
     dp[0]=1;
     sum[0]=1;
     last[s[0]-'a']=0;
     for(int i=1;i<n;i++){
        if(last[s[i]-'a']==-1){
            dp[i]=sum[i-1]+1;
        }
        else
        dp[i]=sum[i-1];
        if(last[s[i]-'a']!=-1){
            dp[i]-=sum[last[s[i]-'a']];
        }
    
        sum[i]=sum[i-1]+dp[i];
        last[s[i]-'a']=i;
     }
     cout<<sum[n-1]<<"\n";
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;

}