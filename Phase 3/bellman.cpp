#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define int long long // Use this to automatically convert all int to long long

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<pair<int, int>, int>> edge;

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edge.push_back({{a, b}, -c}); // negate to find longest path
    }

    vector<int> dis(n + 1, 1e18); // use large constant for INF
    dis[1] = 0;

    for (int i = 1; i < n; i++) {
        for (auto v : edge) {
            int a = v.F.F;
            int b = v.F.S;
            int c = v.S;
            if (dis[a] != 1e18 && dis[a] + c < dis[b]) {
                dis[b] = dis[a] + c;
            }
        }
    }

    bool flag = false;
    for (auto v : edge) {
        int a = v.F.F;
        int b = v.F.S;
        int c = v.S;
        if (dis[a] != 1e18 && dis[b]!=1e18&&dis[a] + c < dis[b]) {
            flag = true;
            break;
        }
    }

    if (flag ) {
        cout << -1 << endl;
    } else {
        cout << -dis[n] << endl; // negate again to get longest path
    }
}

int32_t main() { // use int32_t so that main() still returns int
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
