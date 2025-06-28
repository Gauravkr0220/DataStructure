#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
#define int long long
void solve()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>g(n+1);
    vector<int>indeg(n+1,0);
    vector<int>path(n+1,0);
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        indeg[v]++;
    }
    path[1]=1; // Starting from node 1
    queue<int>q;
    for(int i=1;i<=n;i++)
    {
        if(indeg[i]==0)
        {
            q.push(i);
        }
    }
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        for(auto x:g[node])
        {
            indeg[x]--;
            if(indeg[x]==0)
            {
                q.push(x);
            }
            path[x] = (path[x]%mod+ path[node]%mod)%mod; // Update the number of ways to reach node x
        }
    }
   
        cout<<path[n]<<endl; // Output the number of ways to reach node n
   

}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    
        solve();
    
    
    return 0;
}