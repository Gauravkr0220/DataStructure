#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define PB push_back
#define F first
#define S second

ll n, m;
map<ll, ll> mp;
ll max_, min_;

void pos(ll l, ll r) {
    if (r == max_) max_ = r + 1;
    if (l == min_) min_ = l + 1;
    vector<ll> vec;
    
    // Collect valid keys in the range [l, r] with non-zero values
    for (auto v : mp) {
        if (l <= v.F && v.F <= r && v.S != 0) {
            vec.PB(v.F);
        }
    }
    reverse(vec.begin(), vec.end());  // Reverse to handle from right to left

    // Process the collected keys
    for (ll i = 0; i < vec.size(); i++) {  // Changed from <= to <
        mp[vec[i] + 1] += mp[vec[i]];
        mp[vec[i]] = 0;
    }
}

void neg(ll l, ll r) {
    if (r == max_) max_ = r - 1;
    if (l == min_) min_ = l - 1;
    vector<ll> vec;

    // Collect valid keys in the range [l, r] with non-zero values
    for (auto v : mp) {
        if (l <= v.F && v.F <= r && v.S != 0) {
            vec.PB(v.F);
        }
    }

    // Process the collected keys
    for (ll i = 0; i < vec.size(); i++) {  // Changed from <= to <
        mp[vec[i] - 1] += mp[vec[i]];
        mp[vec[i]] = 0;
    }
}

void solve() {
    cin >> n >> m;
    max_ = LLONG_MIN;
    min_ = LLONG_MAX;
    mp.clear();

    for (int i = 0; i < n; i++) {
        ll g;
        cin >> g;
        mp[g]++;
        max_ = max(max_, g);
        min_ = min(min_, g);
    }

    while (m--) {
        char c;
        ll l, r;
        cin >> c >> l >> r;

        if (l < min_ && r >= min_ && r <= max_) {
            if (c == '+') {
                pos(min_, r);
            } else {
                neg(min_, r);
            }
        } else if (l >= min_ && l <= max_ && r > max_) {
            if (c == '+') {
                pos(l, max_);
            } else {
                neg(l, max_);
            }
        } else if (l >= min_ && l <= max_ && r >= min_ && r <= max_) {
            if (c == '+') {
                pos(l, r);
            } else {
                neg(l, r);
            }
        } else if (l < min_ && r > max_) {
            if (c == '+') {
                pos(min_, max_);
            } else {
                neg(min_, max_);
            }
        }
        cout << max_ << " ";
    }
    cout << endl;
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
