#include<bits/stdc++.h>
using namespace std;
#define int long long
int dp[5005][5005][2];
int n;
vector<int>vec;
int rec(int i,int j,int state)
{
    if(i==j) 
    {
        if(state==0) return vec[i];
        else return 0;
    }
    if(i+1==j) 
    {
        if(state==0) return max(vec[i], vec[j]);
        else return min(vec[i], vec[j]);
    }
    if(dp[i][j][state]!=-1e9) return dp[i][j][state];
    int ans=0;
    if(state==0) // player 1's turn
    {
        ans=max(vec[i]+rec(i+1,j,1-state), vec[j]+rec(i,j-1,1-state));
    }
    else // player 2's turn
    {
        
            ans=min(rec(i+1,j,1-state), rec(i,j-1,1-state));
       
    }
    return dp[i][j][state]=ans;
}
void solve()
{
   cin>>n;
   vec.resize(n);
   for(int i=0;i<n;i++)
   {
    cin>>vec[i];
   } 
   for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            for(int k=0; k<=2; k++){
                dp[i][j][k] = -1e9;
            }
        }
   }
   cout<<rec(0,n-1,0)<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}