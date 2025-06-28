#include<bits/stdc++.h>
using namespace std;

void solve()
{

    int n,m;
    cin>>n>>m;
vector<vector<int>>g(n+1);
vector<int>indeg(n+1,0);
for(int i=0;i<m;i++)
{
    int u,v;
    cin>>u>>v;
    g[u].push_back(v);
    indeg[v]++;
}
vector<int>ans;
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
        ans.push_back(node);
        for(auto x:g[node])
        {
            indeg[x]--;
            if(indeg[x]==0)
            {
                q.push(x);
            }
        }
    }
    if(ans.size()==n)
    {
        for(int i=0;i<ans.size();i++)
        {
            cout<<ans[i]<<" ";
        }
    }
    else {
        cout<<"IMPOSSIBLE"<<endl; 
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
