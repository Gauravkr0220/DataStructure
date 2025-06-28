#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> dis, indeg, parent;

void solve() {
    int n, m;
    cin >> n >> m;

    g.assign(n + 1, {});
    dis.assign(n + 1, INT_MIN); // Distance as negative infinity
    indeg.assign(n + 1, 0);
    parent.assign(n + 1, -1);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        indeg[v]++;
    }

    // Topological sort using Kahn's Algorithm
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (indeg[i] == 0) q.push(i);
    }

    dis[1] = 0; // Path starts from node 1

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int nei : g[node]) {
            if (dis[node]!=INT_MIN&&dis[nei] < dis[node] + 1) {
                dis[nei] = dis[node] + 1;
                parent[nei] = node;
            }
            indeg[nei]--;
            if (indeg[nei] == 0) q.push(nei);
        }
    }

    if (dis[n] == INT_MIN) {
        cout << "IMPOSSIBLE\n";
    } else {
        vector<int> path;
        int temp = n;
        while (temp != -1) {
            path.push_back(temp);
            temp = parent[temp];
        }
        reverse(path.begin(), path.end());
        cout << path.size() << "\n";
        for (int x : path) cout << x << " ";
        cout << "\n";
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
