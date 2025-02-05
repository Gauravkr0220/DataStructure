#include <bits/stdc++.h>
using namespace std;
#define double long double
// using vi = vector<int>;

int n, k;
// vi vec;
vector<vector<double>> dp;
vector<double>vec;
double rec(int level, int cnt) {
    // Base case: If we have reached the end and have at least 'k' wins, return 1 (win)
    if (level == n) {
        if (cnt >= k) return 1;
        return 0; // If we haven't reached 'k' wins, return 0 (loss)
    }

    if (dp[level][cnt] != -1) return dp[level][cnt];

    double ans = 0;
    ans += vec[level] * rec(level + 1, cnt + 1); // Player wins the current round
    ans += (1 - vec[level]) * rec(level + 1, cnt); // Player loses the current round

    return dp[level][cnt] = ans;
}


void solve() {
  
    cin>>n;
    for(int i=0;i<n;i++){
      double g;cin>>g;
      vec.push_back(g);  
    }
   k=n/2+1;
  dp.assign(n+1,vector<double>(n+1,-1));
    double ans=rec(0,0);
    cout<<fixed<<setprecision(10)<<ans<<endl;

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
   
    solve();
    
    return 0;
}
