#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>g;
vector<int>vis;
bool flag=true;
void dfs(int node,int color){
    vis[node]=color;
    for(auto v:g[node]){
        if(!vis[v]){
            dfs(v,3-color);
        }
        else if(vis[v]==color){
            flag=false;
            return ;
        }
        }
    }

void solve(){
    flag=true;
    int n,m;
    cin>>n>>m;
    g.resize(n+1);
    vis.assign(n+1,0);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i,1);
        }
    }
   
    if(flag){
        for(int i=1;i<=n;i++){
            cout<<vis[i]<<" ";
        }
        cout<<endl;
    }
    else {
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