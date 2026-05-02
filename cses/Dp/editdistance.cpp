#include<bits/stdc++.h>
using namespace std;
string s1,s2;
int dp[5005][5005];
int rec(int i,int j)
{
    if(i==s1.size()) return s2.size()-j;
    if(j==s2.size()) return s1.size()-i;

    if(dp[i][j]!=-1) return dp[i][j];
    int ans=1e9;
    
        if(s1[i]==s2[j]){ 
            ans=min(ans,rec(i+1,j+1));
            // add
            ans=min(ans,rec(i,j+1)+1);
            //remove
            ans=min(ans,rec(i+1,j)+1);
            // replace
            ans=min(ans,rec(i+1,j+1)+1);
        }
        else{
            // add
            ans=min(ans,rec(i,j+1)+1);
            //remove
            ans=min(ans,rec(i+1,j)+1);
            // replace
            ans=min(ans,rec(i+1,j+1)+1);
        }
    return dp[i][j]=ans;
}
void solve()
{
    cin>>s1>>s2;
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,0)<<endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}