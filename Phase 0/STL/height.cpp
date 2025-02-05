#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> ps(n), ns(n);
    ps[0] = -1;
    for (int i = 1; i < n; i++) {
        int val = i - 1;
        while (val != -1 && arr[val] > arr[i]) {
            val = ps[val];
        }
        ps[i] = val;
    }

    ns[n-1] = n;
    for (int i = n - 2; i >= 0; i--) {
        int val = i + 1;
        while (val < n && arr[val] >= arr[i]) {
            val = ns[val];
        }
        ns[i] = val;
    }
    map<ll,ll>index;
    for(int i=0;i<n;i++){

        index[arr[i]]=-1;
    }
    for(int i=0;i<n;i++){
        if(index[arr[i]]!=-1){
            int pre=index[arr[i]];
            int preval = ns[pre] - ps[pre] - 1;
            int val= ns[i] - ps[i] - 1;
            if(val>preval) index[arr[i]]=i;
            else continue;
        }
        else index[arr[i]]=i;
    }

    sort(arr.begin(),arr.end());
    vector<ll >ans;
    int cnt=1;
    for(int i=n-1;i>=0;i--){
        ll j=index[arr[i]];
         ll val = ns[j] - ps[j] - 1;
        for (ll k = cnt; k <= val; k++) {
            ans.push_back(arr[i]);
            cnt++;
            if(cnt>n) break;
        }
           if(cnt>n) break;
    }
   
    
    for (int i = 0; i < n; i++) {
        cout<<ans[i]<<" ";
    }
    cout << '\n';
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
