#include<bits/stdc++.h>
using namespace std;
vector<int> vis;
vector<int>parent;
vector<vector<int>>g;
void solve(){
    int n,m;
    cin>>n>>m;
    g.resize(n+1);
    vis.assign(n+1,0);
    parent.assign(n+1,-1);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    queue<int>q;
    q.push(1);
    vis[1]=1;
    parent[1]=-1;
    while(!q.empty()){
        int node =q.front();
        q.pop();
        for(auto v:g[node]){
            if(!vis[v]){
                vis[v]=vis[node]+1;
                parent[v]=node;
                q.push(v);
            }
        }
    }
    if(vis[n]){
        cout<<vis[n]<<endl;
        vector<int>path;
        int v=n;
        while(v!=-1){
            path.push_back(v);
            v=parent[v];
        }
        reverse(path.begin(),path.end());
        for(auto v:path){
            cout<<v<<" ";
        }
        cout<<endl;

    }
    else{
        cout<<"IMPOSSIBLE"<<endl;
    }

}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}