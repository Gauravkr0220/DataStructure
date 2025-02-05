class DisjointSets {
private:
    vector<int> parents;
    vector<int> sizes;
 
public:
    DisjointSets(int size) : parents(size), sizes(size, 1) {
        for (int i = 0; i < size; i++) {
            parents[i] = i; // Initialize each element as its own parent (disjoint sets)
        }
    }
    int find(int x) {
        if (parents[x] != x) {  // Check if x is not already the root (optimized path compression)
            parents[x] = find(parents[x]);  // Recursively find the root
        }
        return parents[x];
    }
    bool unite(int x, int y) {
        int x_root = find(x);
        int y_root = find(y);
        if (x_root == y_root) {
            return false; // Already in the same component
        }
 
        if (sizes[x_root] < sizes[y_root]) {
            swap(x_root, y_root); // Make sure x_root points to the larger tree (union by rank)
        }
        sizes[x_root] += sizes[y_root];
        parents[y_root] = x_root;
        return true;
    }
 
    bool connected(int x, int y) {
        return find(x) == find(y);
    }
};