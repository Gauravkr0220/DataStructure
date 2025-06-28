#include<bits/stdc++.h>
using namespace std; 
#define int long long

void solve(){
    int n,m,q;
    cin>>n>>m>>q;
   
    vector<vector<int>>dist(n+1, vector<int>(n+1, 1e18));
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        if(dist[u][v] > w) { // Only update if the new weight is smaller
            dist[u][v] = w;
            dist[v][u] = w; 
        }
        
        
    }
    for(int i=1;i<=n;i++){
        dist[i][i] = 0; // Distance to self is zero
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dist[i][j] > dist[i][k] + dist[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                    dist[j][i] = dist[i][j]; 
                }
            }
        }
    }
    for(int i=0;i<q;i++){
        int u,v;
        cin>>u>>v;
        if(dist[u][v] == 1e18){
            cout << -1 << endl; // If no path exists
        } else {
            cout << dist[u][v] << endl; // Output the shortest distance
        }
    }
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
        solve();
    
    
    return 0;
}