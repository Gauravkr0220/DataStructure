#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, k;
vector<ll> vec;

bool check(ll mid) {
    ll cnt = 1;
    ll sum = 0;
    
    for (ll i = 0; i < n; i++) {
        if (sum + vec[i] <= mid) {
            sum += vec[i];
        } else {
            sum = vec[i];  // Start a new subarray
            cnt++;
        }
    }
    
    return cnt <= k;  // Return true if we can form `k` or fewer subarrays
}

void solve() {
    cin >> n >> k;
    vec.resize(n);
    ll lo = 0; // Initialize to 0 for now, will be updated
    ll hi = 0;
    
    for (int i = 0; i < n; i++) {
        ll g;
        cin >> g;
        hi += g;      // Sum of all elements as upper bound
        lo = max(lo, g);  // The largest single element should be the lower bound
        vec[i] = g;
    }
    
    ll ans = hi;  // Initially assume the answer is the total sum
    
    while (lo <= hi) {
        ll mid = lo + (hi - lo) / 2;
        
        if (check(mid)) {
            ans = mid;  // Store potential answer
            hi = mid - 1;  // Try to minimize the maximum subarray sum
        } else {
            lo = mid + 1;  // Increase the sum limit
        }
    }
    
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();
    
    return 0;
}
