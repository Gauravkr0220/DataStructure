#include<bits/stdc++.h>
using namespace std;
#define MP make_pair
#define F first
#define S second

using ii =pair<int,int>;
using state=pair<int,int>;
int cost[1001];
vector<vector<pair<int,ii>>>g;//for every node with information of that node
int dis[1001][1001]; //at each distance we can reful to mac of 1001 litre;
int vis[1001][1001];// with that dis do we reach that at same petrol amt
void dijkstra(state st){
    priority_queue<pair<int,state>>pq;
    dist[st.F][st.S]=0;
    pq.push(MP(0,st));
    while(!pq.empty()){
        auto val=pq.top();
        int cur_dist=-val.F;
        int  cur_state=val.S;
        //check visited
        if(visited[cur_state.F][cur_state.S]==1) continue;
       visited[cur_state.F][cur_state.S]==1;
       // very important;
       // try and go to neighbout or refill
       // try to go to neighbour
       for(auto v: g[cur_state.F]){
        if(cur_state.S>=v.S.F){
            //relax
            if(!vis[v.F][cur_state.S-v.S.F]&&dist[v.F][cur_state.S-v.S.F]>cur_dist+0){
                dist[v.F][cur_state.S-v.S.F]=cur_dist;
                pq.push(MP( -dist[v.F][cur_state.S-v.S.F],MP(v.F,cur_state.S-v.S.F)));
            }
        }
         

       }
       if(!vis[cur_state.F][cur_state.S+1]&&dist[cur_state.F][cur_state.S+1]>cur_dist+cost[cur_state.F]){
                dist[cur_state.F][cur_state.S+1]=cur_dist+cost[cur_state.F];
                pq.push(MP( -dist[cur_state.F][cur_state.S+1],MP(cur_state.F,cur_state.S+1)));
            }
    }
}

void solve(){
   int n,m,k;
   cin>>n>>m>>k;
   for(int i=0;i<n;i++){
    for(int j=0;j<=k;j++){
        dist[i][j]=1e9;
        vis[i][j]=0;
    }
   }
   g.resize(n+1);
   int st_node=1,en_node=n;
   for(int i=0;i<1001;i++){
    cin>>cost[i];
   }
   for(int i=0;i<m;i++){
    int p,d;
    int a,b;
    cin>>a>>b;
    cin>>p>>d;
    g[a].push_back({b,{p,d}}); // p petrol used to travel d sitance in a to b
    g[b].push_back({a,{p,d}});
   }
state st={st_node,0};// {node,petrol left}
dijkstra(st);

}
int main(){
      ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
        solve();
  
    return 0;
}