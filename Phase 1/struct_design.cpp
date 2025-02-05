
// Write your code here

// you can set your Template at profile settings [https://maang.in/profile/edit-profile]
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
struct bag{
    ll sum=0;
    map<ll,ll>mp;
    void add(ll x){
        sum+=x;
        mp[x]++;
    }
    void remove(ll x){
        if (mp.find(x) != mp.end()) {
      if (mp[x] != 0) {
        sum -= x;
        mp[x]--;
      }
      if (mp[x] == 0)
        mp.erase(x);  
    }
    }
    void min(){
        if(!mp.empty()) cout<<(*mp.begin()).first<<'\n';
        else cout<<-1<<'\n';
    }
    void max(){
        if(!mp.empty()) cout<<(*mp.rbegin()).first<<'\n';
        else cout<<-1<<'\n';
    }
    void sum_(){
        if(!mp.empty()){
            cout<<sum<<'\n';
        }
        else cout<<0<<'\n';
    }

};
void solve() {
   ll q,n,x;
   cin>>q;
   bag str;
   while(q--){
    cin>>n;
    if(n==1){
        cin>>x;
        str.add(x);
    }
    else if(n==2){cin>>x;
        str.remove(x);}
    else if(n==3){
        char c;
        cin>>c;
        str.min();
    }
    else if(n==4){
        char c;
        cin>>c;
         str.max();
    }
    else if(n==5){
        char c;
        cin>>c;
        str.sum_();
    }
   }
    
    
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
        solve();
   
    return 0;
}