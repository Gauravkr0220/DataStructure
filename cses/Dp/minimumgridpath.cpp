#include<bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>>grid;
vector<vector<char>>ch;
int dp[3005][3005];
int done[3005][3005];
int rec(int i, int j) {
if(i==n-1&& j==n-1) return grid[i][j];
if(i>=n || j>=n) return 1e9;
if(dp[i][j]!=-1) return dp[i][j];
int ans = 1e9;
if(i<n-1&&j<n-1)
{
    if(grid[i+1][j] < grid[i][j+1]) {
        ans = rec(i+1, j);
        done[i][j] = 1; // Move down
    } else if (grid[i+1][j] > grid[i][j+1]) {
        ans = rec(i, j+1);
        done[i][j] = 2; // Move right
    } else {
        int down = rec(i+1, j);
        int right = rec(i, j+1);
        if (down < right) {
            ans = down;
            done[i][j] = 1; // Move down
        } else {
            ans = right;
            done[i][j] = 2; // Move right
        }
    }
}
else if(i<n-1) {
    ans = rec(i+1, j);
    done[i][j] = 1; // Move down
} else if(j<n-1) {
    ans = rec(i, j+1);
    done[i][j] = 2; // Move right
}
return dp[i][j] = ans + grid[i][j];
}
void generate(int i,int j)
{
    if(i==j && i==n-1) { cout<<ch[i][j];return;}
    int x = done[i][j];
    if(x==1)
    {
        cout<<ch[i][j];
        generate(i+1,j);
    }
    else if(x==2) 
   { cout<<ch[i][j];
        generate(i,j+1);}
    return ;
}
void solve()
{
    cin>>n;
    grid.resize(n, vector<int>(n));
    ch.resize(n, vector<char>(n));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            char c;
            cin>>c;
            ch[i][j] = c; 
            grid[i][j] = int(c - 'A'); 
        }
    }
    memset(dp,-1,sizeof(dp));
    memset(done,-1,sizeof(done));
    int ans = rec(0,0);
    generate(0,0);
    cout<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    solve();
    
    return 0;
}