#include<bits/stdc++.h>
using namespace std;
vector<int>vis;
vector<vector<int>>g;
vector<int>parent;
bool flag=true;
vector<int>path;
int ans=0;
void dfs(int node ,int par){
    vis[node]=vis[par]+1;
    for(auto v:g[node]){
        if(!vis[v]){
            parent[v]=node;
            dfs(v,node);
        }
        else if(vis[v]&&v!=par&&flag){
            flag=false;
            path.clear();
            
            ans=0;
            ans=vis[node]-vis[v]+1;
            int x=node;
            while(x!=parent[v]){
                path.push_back(x);
                x=parent[x];
            }
            return;
        }
    }
}
void solve(){
    int n,m;
    cin>>n>>m;
    path.clear();
    g.clear();
    flag=true;
    g.resize(n+1);
    vis.assign(n+1,0);
    parent.assign(n+1,0);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]&&flag){
            dfs(i,0);
        }
    }
    if(flag){
        cout<<"IMPOSSIBLE"<<endl;
    }
    else{
        
        reverse(path.begin(),path.end());
        path.push_back(path[0]);
        cout<<path.size()<<endl;
        for(auto v:path){
            cout<<v<<" ";
        }
        cout<<endl;
    }

}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}