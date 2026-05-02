#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>>vec;
    vec.resize(n+1);
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        vec[u].push_back({v,w});
        
    }
    priority_queue<pair<int,int>>pq;
    vector<int>dist(n+1,1e18);
    vector<int>visited(n+1,0);
    pq.push({0,1}); 
    dist[1] = 0;
    while(!pq.empty()){
        auto v = pq.top();
        pq.pop();
        int d =- v.first, node = v.second;
       
      if(visited[node]) continue; 
        visited[node] = 1;
        for(auto v1 : vec[node]){
            int neighbor = v1.first;
            int weight = v1.second;
            if(dist[neighbor] > d + weight){
                dist[neighbor] = d + weight;
                pq.push({-dist[neighbor], neighbor}); 
            }
        }
    }
    for(int i=1;i<=n;i++){
       
        cout << dist[i] << " ";
    }
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
        solve();
    return 0;
}