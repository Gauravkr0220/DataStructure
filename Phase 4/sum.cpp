#include <bits/stdc++.h>
using namespace std;

#define int long long
int n, q;
vector<int> vec;

// Segment tree node definition with a set of sums
struct node {
    set<int> sums;
    node() {}
    node(int s) {
        sums.insert(s);
    }
};

// Segment tree array to store the nodes
node t[800400];

// Merging two nodes
node merge(node a, node b) {
    node ans;
    // Combine sums from both sides
    for (int sum_a : a.sums) {
        for (int sum_b : b.sums) {
            ans.sums.insert(sum_a + sum_b);  // Add sums from both segments
        }
    }
    // Include sums from the individual segments
    ans.sums.insert(a.sums.begin(), a.sums.end());
    ans.sums.insert(b.sums.begin(), b.sums.end());
    return ans;
}

// Build the segment tree
void build(int index, int l, int r) {
    if (l == r) {
        t[index] = node(vec[l]);  // Leaf node holds the element itself
        return;
    }
    int mid = (l + r) / 2;
    build(2 * index, l, mid);  // Build left child
    build(2 * index + 1, mid + 1, r);  // Build right child
    t[index] = merge(t[2 * index], t[2 * index + 1]);  // Merge the children
}

// Update the segment tree when a value changes
void update(int index, int l, int r, int pos, int val) {
    if (pos < l || pos > r) return;
    if (l == r) {
        t[index] = node(val);  // Leaf node is updated
        vec[l] = val;
        return;
    }
    int mid = (l + r) / 2;
    update(2 * index, l, mid, pos, val);  // Update left child
    update(2 * index + 1, mid + 1, r, pos, val);  // Update right child
    t[index] = merge(t[2 * index], t[2 * index + 1]);  // Merge after update
}

void solve() {
    cin >> n >> q;
    vec.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }

    build(1, 0, n - 1);  // Build the tree
    
    while (q--) {
        int x, y;
        cin >> x >> y;
        x--;  // Convert to 0-based index
        
        // Update the value at index x
        update(1, 0, n - 1, x, y);
        
        // Output the distinct subarray sums
        cout << t[1].sums.size() << endl;
        for (auto sum : t[1].sums) {
            cout << sum << " ";
        }
        cout << endl;

        // Clear the set for the next case
        for(int i=0;i<n;i++)
        t[i].sums.clear();
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
