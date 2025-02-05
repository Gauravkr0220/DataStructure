#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
    int n, set_size, *parent, *rank, max_rank;
    
    UnionFind(int a) {
        n = set_size = a;
        parent = new int[n + 1];
        rank = new int[n + 1];
        max_rank = 1;  // Initialize max rank
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
            rank[i] = 1;
        }
    }

    int find(int x) {
        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void merge(int x, int y) {
        int xroot = find(x);
        int yroot = find(y);

        if (xroot != yroot) {
            if (rank[xroot] >= rank[yroot]) {
                parent[yroot] = xroot;
                rank[xroot] += rank[yroot];
                max_rank = max(max_rank, rank[xroot]);  // Update max rank
            } else {
                parent[xroot] = yroot;
                rank[yroot] += rank[xroot];
                max_rank = max(max_rank, rank[yroot]);  // Update max rank
            }
            set_size--;
        }
    }

    int size() {
        return set_size;
    }

    int getMaxRank() {
        return max_rank;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    
    UnionFind uf(n);
    while (m--) {
        int a, b;
        cin >> a >> b;
        if (uf.find(a) != uf.find(b)) {
            uf.merge(a, b);
        }
        cout << uf.size() << ' ' << uf.getMaxRank() << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
