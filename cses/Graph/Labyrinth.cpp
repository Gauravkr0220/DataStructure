#include<bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define state pair<int,int>
vector<vector<char>>grid;
vector<vector<int>>vis;
vector<vector<int>>dist;
vector<vector<pair<int,int>>>parent;
vector<vector<char>>path;
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
 char c[4]={'R','L','U','D'};
void solve(){
    int n,m;
    cin>>n>>m;
    state start,end;
    grid.assign(n,vector<char>(m));
    for( int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
            if(grid[i][j]=='A'){
                start={i,j};
            }
            else if(grid[i][j]=='B'){
                end={i,j};
            }
        }
    }
    vis.assign(n,vector<int>(m,0));
    path.assign(n,vector<char>(m,'#'));
    dist.assign(n,vector<int>(m,INT_MAX));
    parent.assign(n,vector<pair<int,int>>(m,{-1,-1}));
    queue<state>q;
    q.push(start);
    vis[start.F][start.S]=1;
    dist[start.F][start.S]=0;
    parent[start.F][start.S]={-1,-1};
    while(!q.empty()){
        auto v=q.front();
        q.pop();
        int nodei=v.F;
        int nodej=v.S;
        for(int i=0;i<4;i++){
            int x=nodei+dx[i];
            int y=nodej+dy[i];
            if(x>=0&&x<n&&y>=0&&y<m&&!vis[x][y]&&grid[x][y]!='#'){
                vis[x][y]=1;
                dist[x][y]=dist[nodei][nodej]+1;
                parent[x][y]={nodei,nodej};
                path[x][y]=c[i];
                q.push({x,y});
            }
        }
    }
    if(dist[end.F][end.S]==INT_MAX){
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
    cout<<dist[end.F][end.S]<<endl;
    vector<char>ans;
    while(end.F!=start.F||end.S!=start.S){
        ans.push_back(path[end.F][end.S]);
        auto v=parent[end.F][end.S];
        end.F=v.F;
        end.S=v.S;
    }
    reverse(ans.begin(),ans.end());
    for(auto v:ans){
        cout<<v;
    }
    cout<<endl;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}