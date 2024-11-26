#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    deque<int> vec;
    int ans = 0;

    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '1') {
            vec.push_back(1);
        } else if (s[i] == '0') {
            if (vec.empty()) {
                ans += i + 1;
            } else {
                vec.pop_back();
                ans += i + 1;
            }
        }
    }

    int c = vec.size();
 

    if (c != 0) {
        int n1 = c / 2;
        int i = 1;
        while (i <= c - n1) {
            ans += i;
            i++;
        }
    }
    cout << ans << endl;
}

int main() {
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
