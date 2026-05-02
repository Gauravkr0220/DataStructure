#include<bits/stdc++.h>
using namespace std;
vector<int>vec1,vec2;
int n,m;
int dp[1005][1005];
int done [1005][1005];
int rec(int i,int j)
{
    if(i==n||j==m)
    return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int ans=0;
    if(vec1[i]==vec2[j])
    {
        int x=rec(i+1,j+1)+1;
        if(x>ans) {
            done[i][j]=1;
            ans=x;
        }
    }
    if(rec(i+1,j)>ans)
    {
        done[i][j]=2;
        ans=rec(i+1,j);
    }
     if(rec(i,j+1)>ans)
    {
        done[i][j]=3;
        ans=rec(i,j+1);
    }
    return dp[i][j]=ans;
}
void generate(int i,int j)
{
    if(i==n||j==m) return;
    int x = done[i][j];
    if(x==1)
    {
        cout<<vec1[i]<<" ";
        generate(i+1,j+1);
    }
    else if(x==2) generate(i+1,j);
    else if( x==3) generate(i,j+1);
    return ;
}
void solve()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        int g;
         cin>>g;
         vec1.push_back(g);
    }
    for(int j=0;j<m;j++)
    {
        int g;
         cin>>g;
         vec2.push_back(g);
    }
    memset(dp,-1,sizeof(dp));
    memset(done,-1,sizeof(done));
    int ans=rec(0,0);
    cout<<ans<<endl;
    generate(0,0);

}
signed main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    
    return 0;
}