#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>g;
vector<int>parent;
vector<int>vis;
bool flag=false;
vector<int>ans;
void dfs(int node ,int par)
{   
if(flag) return; // If cycle is already found, exit
vis[node]=1; // Mark the current node as visited  
parent[node]=par; 
for(auto x:g[node])
{   if(flag)    return;
    if(!vis[x]){
        dfs(x,node);
    }
    else if(vis[x]==1&&!flag )
    {   
        flag=true;
        ans.push_back(x);
        int temp=node;
        while(temp!=x)
        {
            ans.push_back(temp);
            temp=parent[temp];
        }
        ans.push_back(x);
        reverse(ans.begin(),ans.end()); // Reverse to get the correct order of the cycle

    }
}
    vis[node]=2;
}
void solve()
{
    int n,m;
    flag=false;
    cin>>n>>m;
    g.resize(n+1);
    parent.resize(n+1,-1);
    vis.resize(n+1,0);
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
    }
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==0&&!flag)
        {
            dfs(i,-1);
        }
    }
    if(flag)
    {
        cout<<ans.size()<<endl;
        for(int i=0;i<ans.size();i++)
        {
            cout<<ans[i]<<" ";
        }
    }
    else
    {
        cout<<"IMPOSSIBLE"<<endl;
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    
        solve();
   
    return 0;
}