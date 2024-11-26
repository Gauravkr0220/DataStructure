#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;

int n, k;
vi vec;
vector<int> dp;

int rec(int x) {
    if (x == 0) return 0;  // Base case: If no stones are left, current player loses
    if (dp[x] != -1) return dp[x];  // Memoization: return if already computed

    for (int a : vec) {
        if (x - a >= 0 && rec(x - a) == 0) {
            return dp[x] = 1;  // If we can leave the opponent in a losing state, current player wins
        }
    }
    return dp[x] = 0;  // If no winning move is found, current player loses
}

void solve() {
    cin >> n >> k;
    vec.resize(n);
    dp.assign(k + 1, -1);  // Initialize dp array with size k+1, all set to -1

    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }

    int result = rec(k);
    if (result == 1) {
        cout << "First" << endl;
    } else {
        cout << "Second" << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
   
    solve();
    
    return 0;
}
