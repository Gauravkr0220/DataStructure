#include <bits/stdc++.h>
using namespace std;

using state = pair<int, int>;

#define F first
#define S second

int n, k;
vector<vector<int>> vec;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int bfs(state no, int par) {
    vector<vector<int>> vis(n, vector<int>(10, 0));  // Initialize visit matrix
    vector<state> temp;
    queue<state> q;

    q.push(no);
    vis[no.F][no.S] = 1;
    temp.push_back(no);

    while (!q.empty()) {
        state node = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int x = node.F + dx[i];
            int y = node.S + dy[i];

            if (x >= 0 && x < n && y >= 0 && y < 10 && vec[x][y] == par && !vis[x][y]) {
                vis[x][y] = 1;
                temp.push_back({x, y});
                q.push({x, y});
            }
        }
    }

    if (temp.size() >= k) {
        for (auto& t : temp) {
            vec[t.F][t.S] = 0;  // Set the connected component to 0
        }
        return 1;
    }

    return 0;
}

void solve() {
    cin >> n >> k;
    vec.assign(n, vector<int>(10, 0));

    // Input handling: converting input strings to the 2D grid
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < 10; j++) {
            vec[i][j] = s[j] - '0';
        }
    }

    while (true) {
        int cnt = 0;

        // Search for all connected components and process them
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 10; j++) {
                if (vec[i][j] != 0) {
                    cnt += bfs({i, j}, vec[i][j]);
                }
            }
        }

        // If no components were removed, we are done
        if (cnt == 0) break;

        // Gravity effect: Drop the blocks after removal
        for (int j = 0; j < 10; j++) {
            vector<int> a;
            for (int i = n - 1; i >= 0; i--) {
                if (vec[i][j] != 0) {
                    a.push_back(vec[i][j]);
                }
            }

            // Fill the column from the bottom with the remaining blocks
            int k = 0;
            for (int i = n - 1; i >= 0; i--) {
                if (k < a.size()) {
                    vec[i][j] = a[k++];
                } else {
                    vec[i][j] = 0;
                }
            }
        }
    }

    // Output the final grid
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 10; j++) {
            cout << vec[i][j] << ' ';
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}
