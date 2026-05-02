// https://maang.in/playlists/Advanced-DSU-3358?resourceUrl=cs82-cp497-pl3358-rs7824&returnUrl=%5B%22%2Fcourses%2FGraphs-from-Zero-to-Pro-82%3Ftab%3Dchapters%22%5D
#include <bits/stdc++.h>
using namespace std;
using ll= long long;
int n;
set<int>col[100010];
vector<vector<int>>g;
int val[100010];
int ans[100010];
int merge(int a,int b){
    if(cols[a].size()<cols[b].size()) swap(a,b);
    for(auto v:cols[b]) cols[a].insert(v);
    cols[b].clear();
    return a;
}
int dfs(int node,int par){
    int cur_Set=val[node];
    for(auto v:g[node]){
        if(v!=par){
            cur_set=merge(cur_Set,dfs(v,node));
        }
    }
    ans[node]=cols[cur_Set].size();
    return cur_Set;
}
void solve() {
     cin>>n;
     for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        col[i].insert(x);
        val[i]=i;
     }
     for(int i=0; i<=n;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
     }
     dfs(1,0);
     for(int i=1;i<=n;i++){
       cout<<ans[i]<<" ";
     }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
        solve();
  
    return 0;
}