#include <bits/stdc++.h>
int n;
using namespace std;
int rec(int level){
    if(level==n) return 1;
    int ways=0;
    for(int i=1;i<=3;i++){
        if(level+i<=n) ways+=rec(level+i);
    }
    return ways;
}
void solve() {
    cin>>n;
    int ans=rec(0);
    cout<<ans<<endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}