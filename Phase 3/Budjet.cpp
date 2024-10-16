
// Write your code here

// you can set your Template at profile settings [https://maang.in/profile/edit-profile]
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
using state1 = pair<ll, ll>;
using state = pair<ll, pair<ll, ll>>;
vector<vector<state1>> g;
vector<vector<int>> vis;
vector<vector<int>> cost;
vector<int> pe;

int n, m, c, A, B;

void solve()
{
//     cin >> n >> m;
//     g.resize(n + 1);
//     vis.assign(n + 1, vector<int>(105, 0));
//     cost.assign(n + 1, vector<int>(105, 1e9));
//     for (int i = 0; i < m; i++)
//     {
//         ll u, v, d;
//         cin >> u >> v >> d;
//         g[u].push_back({v, d});
//         g[v].push_back({u, d});
//     }
//     for (int i = 1; i <= n; i++)
//     {
//         int p;
//         cin >> p;
//         pe.push_back(p);
//     }
//     cin >> A >> B >> c;

//     state st = {-0, {A, 0}};
//     cost[A][0] = 0;
//     priority_queue<state> pq;
//     pq.push(st);
//     while (!pq.empty())
//     {
//         state it = pq.top();
//         pq.pop();
//         ll cur_cost = -(it.F);
//         state1 cur_state = it.S;
//         if (vis[cur_state.F][cur_state.S] == 1)
//             continue;
//         vis[cur_state.F][cur_state.S] = 1;
//         for (auto v : g[cur_state.F])
//         {
//             if (cur_state.S >= v.S)
//             {
//                 if (cost[v.F][cur_state.S - v.S] > cur_cost + 0)
//                 {
//                     cost[v.F][cur_state.S - v.S] = cur_cost;
//                     pq.push({-cur_cost, {v.F, cur_state.S - v.S}});
//                 }
//             }
//         }
//         if (cur_state.S < c && cost[cur_state.F][cur_state.S + 1] > cur_cost + pe[cur_state.F])
//         {
//             cost[cur_state.F][cur_state.S + 1] = cur_cost + pe[cur_state.F];
//             pq.push({-(cur_cost + pe[cur_state.F]), {cur_state.F, cur_state.S + 1}});
//         }
//     }

//     int min_ = INT_MAX;
//     for (int i = 0; i < 105; i++)
//     {
//         min_ = min(min_, cost[B][i]);
//     }
//     cout << min_ << endl;
// }

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}