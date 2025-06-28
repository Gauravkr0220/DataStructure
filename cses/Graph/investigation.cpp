#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
void solve()
{
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>>g(n+1);
    vector<int>vis(n+1,0);
    vector<int>dist(n+1,1e18);
    vector<int>routes(n+1,0);
    vector<int>miniflight(n+1,1e18);
    vector<int>maxeflight(n+1,-1e18);
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
       
    }

    dist[1]=0;
    routes[1]=1;
    miniflight[1]=0;
    maxeflight[1]=0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
    pq.push({0,1}); 
    while(!pq.empty())
    {
        auto v= pq.top();
        pq.pop();
        int node = v.second;
        int d = v.first;
        if(vis[node]) continue;
        vis[node] = 1; 
        for(auto x:g[node])
        {
            if(dist[x.first] > d + x.second)
            {
                dist[x.first] = d + x.second;
                routes[x.first] = routes[node];
                miniflight[x.first] = miniflight[node]+1;
                maxeflight[x.first] = maxeflight[node]+1;
                pq.push({dist[x.first], x.first});
            }
            else if(dist[x.first] == d + x.second)
            {
                routes[x.first] = (routes[x.first]%mod+routes[node]%mod)%mod;
                miniflight[x.first] = min(miniflight[x.first], miniflight[node]+1);
                maxeflight[x.first] = max(maxeflight[x.first], maxeflight[node]+1);
            }
        }
    }
    cout<<dist[n]<<" "<<routes[n]<<" "<<miniflight[n]<<" "<<maxeflight[n]<<endl;

}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
    
    return 0;
}