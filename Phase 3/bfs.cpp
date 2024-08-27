#include <bits/stdc++.h>
using namespace std;
using ll= long long;
int n,m;
vector<vector<char>>arr;
using state=pair<int,int>;
vector<vector<state>> par;
#define F first
#define S second

vector<vector<int>>dis;
int INF=100;
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};
void path_(state en){
    state cur=en;
    vector<state> path;
    while(cur!= make_pair(-1,-1)){
        path.push_back(cur);
        cur=par[cur.F][cur.S];
    }
    reverse(path.begin(),path.end());
    for(auto v:path){
        cout<<v.F<<" "<<v.S<<endl;    }

}
void distance_map(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<dis[i][j]<<"  ";
        }
        cout<<endl;
    }
}
bool is_valid(int x,int y){
    if(x>=0&&x<n&&y>=0&&y<m&&arr[x][y]!='#'){
        return 1;
    }
    return 0;
}
vector<state> neigbours(state node){
    vector<state> neigh;
    for(int i=0;i<4;i++){
        int x=node.F+dx[i];
        int y=node.S+dy[i];
        if(is_valid(x,y)){
            neigh.push_back(make_pair(x,y));
        }
    }
    return neigh;
}
void bfs(state st_node){
    dis.assign(n,vector<int>(m,INF));
    par.assign(n,vector<state>(m,make_pair(-1,-1)));
     queue<state> q;
    
     dis[st_node.F][st_node.S]=0;
     q.push(st_node);
     while(!q.empty()){
        state node=q.front();
        q.pop();
        for(auto v:neigbours(node)){
           if(dis[v.F][v.S]==INF){
            dis[v.F][v.S]=dis[node.F][node.S]+1;
            par[v.F][v.S]=node;
            q.push(v);
           } 
        }
     }

}
void solve() {
     cin>>n>>m;
     arr.resize(n);
     state st,en;
     for(int i=0;i<n;i++){
        arr[i].resize(m);
        for (int j=0;j<m;j++){
            cin>>arr[i][j];
            if(arr[i][j]=='S'){
                st={i,j};
            }
            else if(arr[i][j]=='F'){
                en={i,j};
            }
        }

     }
     bfs(st);
     if(dis[en.F][en.S]==INF)cout<<"Not reachable"<<endl;
      else cout<<dis[en.F][en.S]<<endl;
    distance_map();
    path_(en);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
        solve();
  
    return 0;
}