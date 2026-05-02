#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<vector<int>>g;
vector<int>vis;
vector<vector<int>>comp;
vector<int>temp;
void dfs(int node,vector<int>& temp){
    vis[node]=1;
    temp.push_back(node);
    for(auto v:g[node]){
        if(!vis[v]){
            dfs(v,temp);
        }
    }
}
 void solve(){
    cin>>n>>m;
    g.resize(n+1);
    comp.clear();
    temp.clear();
    g.clear();
    vis.assign(n+1,0);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        temp.clear();
        if(!vis[i]){
            dfs(i,temp);
            comp.push_back(temp);
        }
       
        
    }
    cout<<comp.size()-1<<endl;;
    for(int i=1;i<comp.size();i++){
        cout<<comp[i][0]<<" "<<comp[i-1][0]<<endl;
    }
    return ;
 }
  signed main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
  }