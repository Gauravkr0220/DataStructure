#include<bits/stdc++.h>
using namespace std;
#define int long long

    vector<vector<int>>vis;
    int dx[4]={0,0,-1,1};
    int dy[4]={1,-1,0,0};
    void dfs(int x,int y,vector<vector<char>>& grid,int n,int m){
        vis[x][y]=1;
        for(int i=0;i<4;i++){
            int x_=x+dx[i];
            int y_=y+dy[i];
            if(x_>=0&&x_<n&&y_>=0&&y_<m&&!vis[x_][y_]&&grid[x_][y_]=='.'){
                dfs(x_,y_,grid,n,m);
            }
        }
    }

void solve() {
    int n,m;
    cin>>n>>m;
    vector<vector<char>>grid;
    grid.assign(n,vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
 
        vis.assign(n,vector<int>(m,0));
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j]&&grid[i][j]=='.'){
                    cnt++;
                    dfs(i,j,grid,n,m);
                }
            }
        }
        cout<<cnt<<endl;
    }

    signed main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(0);
            solve();
        
    }