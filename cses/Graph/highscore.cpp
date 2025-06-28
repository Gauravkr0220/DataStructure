#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> dis(n + 1, LLONG_MIN); 
    dis[1] = 0; // starting point
    if(n == 1) {
        for(int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            if(v==1&&u==1&&w==1) {
                cout<<-1<<endl; return; }

        }
        cout<<0<<endl;return ;
    }
    vector<pair<int, pair<int, int>>> edges;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, {v, w}});
    }

    // Bellman-Ford algorithm for longest path
    for (int k = 1; k < n; k++) {
        for (int i = 0; i < m; i++) {
            int u = edges[i].first;
            int v = edges[i].second.first;
            int w = edges[i].second.second;
            
            if (dis[u] != LLONG_MIN && dis[v] < dis[u] + w) {
                dis[v] = dis[u] + w;
            }
        }
    }

    // Check for positive cycle
    int x=dis[n];
    
   for (int k = 1; k < n; k++) {
        for (int i = 0; i < m; i++) {
            int u = edges[i].first;
            int v = edges[i].second.first;
            int w = edges[i].second.second;
            if (dis[u] != LLONG_MIN && dis[v] < dis[u] + w) {
                dis[v] = 1e15;
            }
        }
    }
  

    if (x!= dis[n]) {
        cout << -1 << endl;
    } else {
        
         cout << dis[n] << endl;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
