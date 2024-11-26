#include <bits/stdc++.h>
using namespace std;

// Define pair for readability
#define MP make_pair
#define state pair<int,int>
#define F first 
#define S second
#define ll long long
vector<vector<pair<ll,ll>>> g;  // Graph adjacency list
vector<vector<ll>> cost;        // Stores cost to each node
vector<vector<ll>> vis;         // Visited array

void solve() {
   ll n, m;
   cin >> n >> m;
   
   g.resize(n + 1);
   cost.assign(n + 1,  vector<ll>(2, 1e18));
   vis.assign(n + 1, vector<ll>(2, 0));
   
   // Input the graph
   for (ll i = 0; i < m; i++) {
      ll a, b, d;
      cin >> a >> b >> d;
      g[a].push_back(MP(b, d));
   }
   
   // Initialize cost for the start node
   cost[1][0] = 0;
   
   priority_queue<pair<ll, state>, vector<pair<ll, state>>, greater<pair<ll, state>>> pq;
   pq.push({0, {1, 0}});
   
   while (!pq.empty()) {
      auto it = pq.top();
      pq.pop();
      
      ll cur_cost = it.F;
      state cur_state = it.S;
      ll cur_node = cur_state.F;
      ll discount_used = cur_state.S;
      
      if (vis[cur_node][discount_used] == 1) continue;
      vis[cur_node][discount_used] = 1;
      
      for (auto v: g[cur_node]) {
         ll next_node = v.F;
         ll edge_cost = v.S;
         
         if (discount_used == 0) {
            // First case: no discount applied
            // Update cost without discount
            if (cost[next_node][0] > cur_cost + edge_cost) {
               cost[next_node][0] = cur_cost + edge_cost;
               pq.push(MP(cost[next_node][0], MP(next_node, 0)));
            }
            // Apply discount and update cost
            if (cost[next_node][1] > cur_cost + edge_cost / 2) {
               cost[next_node][1] = cur_cost + edge_cost / 2;
               pq.push(MP(cost[next_node][1], MP(next_node, 1)));
            }
         } else {
            // Discount already used, only update the discounted path
            if (cost[next_node][1] > cur_cost + edge_cost) {
               cost[next_node][1] = cur_cost + edge_cost;
               pq.push(MP(cost[next_node][1], MP(next_node, 1)));
            }
         }
      }
   }
   
   // Output the minimum cost to reach node `n`
   ll result = min(cost[n][0], cost[n][1]);
   
       cout << result << endl;
 
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    solve();
    // heuhpfuirehubfirebirebvevjineivn
    
    return 0;
}
