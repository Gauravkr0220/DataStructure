#include <bits/stdc++.h>
using namespace std;
vector<int> g[100100];
int dep[100100];
int par[100100];

void dfs(int node,int parent,int depth){
    dep[node]=depth;
    par[node]=parent;
    for (auto v:g[node]){
        if(v!=parent){
            dfs(v,node,depth+1);
            
        }
    }
   
}
void solve()
{
   int n;
    cin>>n;
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    } 
    dfs(1,0,0);
    int max_=1;
    for(int i=2;i<=n;i++){
        if(depth[i]>depth[max_]){
            max_=i;
        }
    }
    dfs(max_,0,0);
    int max_=1;
    for(int i=2;i<=n;i++){
        if(depth[i]>depth[max_]){
            max_=i;
        }
    }
    cout<<depth[max_]<<endl;
    // as we not checking by previous value so donot need to clear depth array




}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}