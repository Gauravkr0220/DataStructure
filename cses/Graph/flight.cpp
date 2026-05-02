#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
 #define int long long
void solve()
{
    int n,m,k;
    cin>> n >> m >> k;
    vector<vector<pair<int,int>>>g(n+1);
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>> u >> v >> w;
        g[u].push_back({v,w});
       
    }
    priority_queue<pair<int,int>>pq;
    vector<int>vis(n+1,0);
    pq.push({0,1}); // {cost, node}
    vector<int>ans;
    while(!pq.empty()){
        if(ans.size() == k) break; 
        auto v = pq.top();
        pq.pop();
        int cost = -v.first; // Negate to get the actual cost
        int node = v.second;
        if(vis[node]>=k) continue; // Skip if already visited
        vis[node] ++; // Mark the node as visited
        if(node==n)
        {
            ans.push_back(cost);
        }
        for(auto x:g[node]){
            int nextNode = x.first;
            int nextCost = x.second;
            pq.push({-(cost + nextCost), nextNode}); // Negate cost for max-heap behavior
        }
    }
    for(int i=0;i<ans.size();i++){
        cout<< ans[i] << " ";
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t = 1; // Number of test cases
    // cin >> t; // Uncomment if you want to read number of test cases
    while (t--) {
        solve();
    }
    
    return 0;
}