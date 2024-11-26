#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<bool> isPrime(200005, true);
void precal(){
    isPrime[0] = isPrime[1] = false;         // 0 and 1 are not prime numbers

    for (int p = 2; p * p <= 200005; ++p) {
        if (isPrime[p]) {
            // Mark all multiples of p as non-prime
            for (int i = p * p; i <= 200005; i += p) {
                isPrime[i] = false;
            }
        }
    }
}
void solve() {
  int n,c;
  cin>>n>>c;
  if((n+1)/2!=c) {cout<<-1<<endl; return ;}
  else{
    int ans=n,delay=1;
    for(int i=2;i<n;i++){
        if(isPrime[i]&&n%i==0){
            ans=n/i;
            delay=i;
        }
    }
    // cout<<delay<<endl;
    cout<<ans<<endl;
    for(int i=1;i<=n;i+=delay){
        cout<<i<<' ';
    }
    cout<<endl;
    return;
  }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
   precal();
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
