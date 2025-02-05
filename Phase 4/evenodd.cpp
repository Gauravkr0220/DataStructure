// https://maang.in/problems/Even-and-Odd-Queries-405?resourceUrl=cs99-cp559-pl3763-rs405&returnUrl=/courses/Premium-Day-Wise-Course-99?tab=chapters
#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, q;
vector<int> vec;

struct node {
    int even;
    int odd;
    node(int m = 0, int c = 0) {
        even = m;
        odd = c;
    }
};

vector<node> t;

// Function to merge two nodes
node merge(node a, node b) {
    return node(a.even+b.even,a.odd+b.odd);
}

// Build the segment tree
void build(int index, int l, int r) {
    if (l == r) {
        if(vec[l]%2==0)
        t[index] = node(1, 0);
        else t[index] = node(0, 1);
        return;
    }
    int mid = (l + r) / 2;
    build(2 * index, l, mid);
    build(2 * index + 1, mid + 1, r);
    t[index] = merge(t[2 * index], t[2 * index + 1]);
}

// Update a value in the segment tree
void update(int index, int l, int r, int pos, int val) {
    if (pos < l || pos > r) return;
    if (l == r) {
        if(val%2==0)
        t[index] = node(1, 0);
        else t[index] = node(0, 1);
        vec[l] = val;
        return;
    }
    int mid = (l + r) / 2;
    update(2 * index, l, mid, pos, val);
    update(2 * index + 1, mid + 1, r, pos, val);
    t[index] = merge(t[2 * index], t[2 * index + 1]);
}

// Query for the minimum value and its frequency in a range
node query(int index, int l, int r, int lq, int rq) {
    if (l > rq || r < lq) return node(0, 0); // Return a default node
    if (lq <= l && r <= rq) return t[index];   // Fully within range
    int mid = (l + r) / 2;
    return merge(query(2 * index, l, mid, lq, rq), query(2 * index + 1, mid + 1, r, lq, rq));
}

void solve() {
    cin >> n ;
    vec.resize(n);
    t.resize(4 * n); // Dynamically allocate space for the segment tree

    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }

    build(1, 0, n - 1);
    cin>>q;
    while (q--) {
        int type;
        cin >> type;

        if (type == 0) {
            int i, x;
            cin >> i >> x;
            i--; 
            update(1, 0, n - 1, i, x);
        } else if (type == 1) {
            int l, r;
            cin >> l >> r;
            l--; r--; // Convert to 0-based index
            node ans = query(1, 0, n - 1, l, r);
            cout << ans.even<< endl;
        }
        else if (type == 2) {
            int l, r;
            cin >> l >> r;
            l--; r--; // Convert to 0-based index
            node ans = query(1, 0, n - 1, l, r);
            cout << ans.odd<< endl;
        }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
