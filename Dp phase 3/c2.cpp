#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
 
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
       
    }
    
   
  
    sort(a.begin(), a.end());
    
    int i = 0, j = n - 1;
    
   
    while (i <=j) {
        if (a[i] + a[j] > a[n - 1]) {
            j--;
        } else {
            i++;
        }
    }
    
    cout << i << endl;
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
