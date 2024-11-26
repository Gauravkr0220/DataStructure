//https://codeforces.com/contest/706/my
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll  n;
    cin>>n;
    vector<ll>vec;
    for(int i=0;i<n;i++){
        ll g;
        cin>>g;
        vec.push_back(g);
    }
    vector<ll>temp;
    ll cnt=0;
    temp.push_back(vec[0]);
      for(int i=1;i<n;i++){
       if(temp.back()<vec[i]){
        temp.push_back(vec[i]);
        cnt++;
       }
       else{
        auto it=lower_bound(temp.begin(),temp.end(),vec[i])-temp.begin();
        temp[it]=vec[i];
       }
    }
    cout<<temp.size()<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        solve();
    return 0;
}
