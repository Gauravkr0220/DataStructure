//https://maang.in/problems/Edit-Distance-1262?resourceUrl=cs99-cp522-pl3614-rs1262&returnUrl=/courses/Premium-Day-Wise-Course-99?tab=chapters
#include <bits/stdc++.h>
using namespace std;
string s1,s2;
int dp[505][505];
int n,m;
int rec(int i,int j){
     if (i == n) return m - j; 
    if (j == m) return n - i; 

    if(dp[i][j]!=-1) return dp[i][j];
   int ans=0;
    ans=min({rec(i+1,j),rec(i,j+1),rec(i+1,j+1)})+1;
    if(s1[i]==s2[j]) ans=min(ans,rec(i+1,j+1));
    return dp[i][j]=ans;
}
void solve() {
   cin>>s1>>s2;
      memset(dp,-1,sizeof(dp));
    n=s1.size();
    m=s2.size();
    cout<<rec(0,0);
    
    
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
        solve();
    
    return 0;
}