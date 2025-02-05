#include <bits/stdc++.h>
using namespace std;

struct node {
    int child[2];
    int freq;
    
    node() {
        child[0] = child[1] = -1;
        freq = 0;
    }
};

struct trie {
    vector<node> nodes;

    trie() {
        nodes.emplace_back(); 
    }

    void insert(int n) {  
        int LN = 32; // Assuming 32-bit numbers
        int cur_node_idx = 0;
        nodes[cur_node_idx].freq++;

        for (int i = LN - 1; i >= 0; i--) {
            int x = (n >> i) & 1; // Extract i-th bit
            
            if (nodes[cur_node_idx].child[x] == -1) {
                nodes.emplace_back(); // Add new node
                nodes[cur_node_idx].child[x] = nodes.size() - 1;
            }
            cur_node_idx = nodes[cur_node_idx].child[x];
            nodes[cur_node_idx].freq++;
        }
    }

    void remove(int n) {  
        int LN = 32; // Assuming 32-bit numbers
        int cur_node_idx = 0;
        nodes[cur_node_idx].freq--;

        for (int i = LN - 1; i >= 0; i--) {
            int x = (n >> i) & 1; 
            int next_idx = nodes[cur_node_idx].child[x];

            nodes[next_idx].freq--;

            
            
            cur_node_idx = next_idx;
        }
    }

    int query(int n) {  
        int LN = 32;
        int cur_node_idx = 0;
        int max_xor = 0;

        for (int i = LN - 1; i >= 0; i--) {
            int x = (n >> i) & 1; 
            if (nodes[cur_node_idx].child[1^x] != -1 && nodes[nodes[cur_node_idx].child[1^x]].freq > 0) {
                max_xor |= (1LL << i); 
                cur_node_idx = nodes[cur_node_idx].child[1^x];
            } else if (nodes[cur_node_idx].child[x] != -1 && nodes[nodes[cur_node_idx].child[x]].freq > 0) {
                cur_node_idx = nodes[cur_node_idx].child[x];
            }
        }
        return max_xor;
    }
};

void solve() {
    int q;
    cin >> q;
    trie t;
    t.insert(0);
    while (q--) {
        char c;
        int x;
        cin >> c >> x;

        if (c == '+') {
            t.insert(x);
        } else if (c == '-') {
            t.remove(x);
        } else {
            cout << t.query(x) << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
   
        solve();


    return 0;
}
