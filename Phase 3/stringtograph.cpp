#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> g;
vector<int> col;

bool is_cycle = 0;
vector<int> any_cycle;
using ll = long long;
vector<vector<ll>> dis;
vector<vector<ll>> par;
vector<vector<int>>g;
ll getvalue(string s){
    ll val=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='1'){
            val=(val<<1)+1;
        }
        else val=val<<1;
    }
    return val;
}

bool ban[(1<<20)];
void addedge(int u,int v){
    if(!ban[u]&&!ban[v]){
        g[u].push_back(v);
        g(v).push_back(u);
    }

}
void solve()
{
    string s;
    cin>> s;
    g.resize(1<<20);
    ll source_val=getvalue(s);
    string end;
    cin>>end;
    int k;
    cin>>k;
    for(int i=0;i<k;i++){
        string l;
        cin>>l;
        ban[getvalue(l)]=true;
    }
    ll end_val=getvalue(end);
    for(int i=0;i<(1<<20);i++){
        for(int j=0;j<20;j++){
                addedge(i,i^(1<<j));
        }
    }


}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}