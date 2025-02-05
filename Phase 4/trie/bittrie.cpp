#include <bits/stdc++.h>
using namespace std;

#define int long long
int g;
struct TrieNode {
    TrieNode* child[2]; 
    TrieNode() {
        child[0] = child[1] = nullptr;
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() { root = new TrieNode(); }

   
    void insert(int num) {
        TrieNode* node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!node->child[bit]) {
                node->child[bit] = new TrieNode();
            }
            node = node->child[bit];
        }
    }

   
    int getMaxXOR(int num) {
        TrieNode* node = root;
        int maxXOR = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (node->child[1 - bit]) {  
                maxXOR |= (1LL << i);
                node = node->child[1 - bit];
            } else {
                node = node->child[bit];
            }
        }
        return maxXOR;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Trie trie;
    trie.insert(0); 
    
    int prefixXOR = 0, maxSubarrayXOR = 0;
    
    for (int i = 0; i < n; i++) {
        prefixXOR ^= arr[i];  
        maxSubarrayXOR = max(maxSubarrayXOR, trie.getMaxXOR(prefixXOR));
        trie.insert(prefixXOR); 
    }

    cout << maxSubarrayXOR << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
