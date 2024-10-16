#include <bits/stdc++.h>
using namespace std;

int ans[100100];
int val[100100];
void dfs(int node,int par,int maxValue, int minValue){
    ans[node]=max(abs(val[node]-maxValue),abs(minValue-val[node]));
    for (auto v: g[node]){
        if(v!=par){
            dfs(v,node,max(maxValue,val[node]),min(minValue,val[node]));
        }
    }
}
void solve()
{   dfs(root,-1,-1e9,1e9);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}