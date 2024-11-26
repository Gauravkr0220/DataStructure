//https://maang.in/problems/Destroy-Coloured-Gemstones-179?resourceUrl=cs99-cp522-pl3616-rs179&returnUrl=/courses/Premium-Day-Wise-Course-99?tab=chapters
#include <bits/stdc++.h>
using namespace std;
int n;
vector<int>vec;
int dp[105][105];

void solve(){
    int x,y,k;
    cin>>x>>y>>k;
    int c=min(x,y);
    cout<<0<<' '<<0<<' '<<c<<' '<<c<<endl;
    cout<<c<<' '<<0<<' '<<0<<' '<<c<<endl;

    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}