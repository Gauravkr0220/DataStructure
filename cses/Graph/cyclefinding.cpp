#include <bits/stdc++.h>
using namespace std;
#define int long long

const int INF = 1e18;
vector<int> dist, parent;
int n, m;

void solve() {
    cin >> n >> m;
    vector<tuple<int, int, int>> edges;
    dist.assign(n + 1, 0); // initialize all distances to 0 to detect negative cycle anywhere
    parent.assign(n + 1, -1);

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    int x = -1;
    for (int i = 1; i <= n; ++i) {
        x = -1;
        for (auto g : edges) {
            int u, v, w;
            tie(u, v, w) = g;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                x = v;
            }
        }
    }

    if (x == -1) {
        cout << "NO\n"; // no negative cycle
    } else {
        cout << "YES\n";
        // recover cycle
        for (int i = 1; i <= n; ++i) {
            x = parent[x];
        }

        vector<int> cycle;
        for (int v = x; ; v = parent[v]) {
            cycle.push_back(v);
            if (v == x && cycle.size() > 1)
                break;
        }
        reverse(cycle.begin(), cycle.end());
        for (int v : cycle)
            cout << v << " ";
        cout << "\n";
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
