#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<pair<ll, ll>> intervals(n);
    vector<ll> starts;

    for (int i = 0; i < n; i++) {
        ll l, r;
        cin >> l >> r;
        intervals[i] = {l, r};
        starts.push_back(l);
    }

    // Sort intervals by starting point and by -ending point (smaller range first)
    sort(intervals.begin(), intervals.end());
    sort(starts.begin(), starts.end());

    vector<ll> result(n, 0);

    for (int i = 0; i < n; i++) {
        ll li = intervals[i].first, ri = intervals[i].second;
        ll minL = li, maxR = ri;

        // Binary search for intervals that can be predictors
        auto it = lower_bound(starts.begin(), starts.end(), li);
        int idx = it - starts.begin();

        for (int j = idx; j < n; j++) {
            ll lj = intervals[j].first, rj = intervals[j].second;
            if (lj > li || rj < ri) break; // Not a predictor if it doesn't contain [li, ri]
            minL = max(minL, lj);          // Update intersection range
            maxR = min(maxR, rj);          // Update intersection range
        }

        // If the range is valid and not equal to [li, ri], compute strongly recommended
        if (minL <= maxR && (minL != li || maxR != ri)) {
            result[i] = (maxR - minL + 1) - (ri - li + 1);
        }
    }

    // Output results for this test case
    for (auto x : result) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
