
// Write your code here

// you can set your Template at profile settings [https://maang.in/profile/edit-profile]
#include <bits/stdc++.h>
using namespace std;
using state=pair<int,int>;
#define F first
#define S second
void solve() {
   int n;
   cin>>n;
   vector<int>ladder;
   ladder.resize(101);
   vector<int>snake;
    snake.resize(101);
    vector<bool>ladderb;
   ladderb.resize(101);
   vector<bool>snakeb;
    snakeb.resize(101);
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        ladder[a]=(b);
        ladderb[a]=true;
    }
    int m;cin>>m;
     for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        snake[a]=(b);
        snakeb[a]=true;
    }
    vector<vector<int>>vis;
    vis.assign(101,vector<int>(101,0));
    vector<int>move;
    move.assign(101,1e9);
    state st={0,1};
    move[1]=0;
    priority_queue<state>pq;
    pq.push(st);
    while(!pq.empty()){
        state it =pq.top();
        pq.pop();
        int cur_move=-it.F;
        int cur_node=it.S;
        if(vis[cur_node][cur_move]==1) continue;
        vis[cur_node][cur_move]=1;
        for(int i=1;i<=6;i++){
           int next_node=cur_node+i;
           if(next_node<=100){
            if(move[next_node]>move[cur_node]+1&&ladderb[next_node]){
                move[next_node]=move[cur_node]+1;
                if(move[ladder[next_node]]>move[cur_node]+1){
                move[ladder[next_node]]=move[cur_node]+1;
                pq.push({-move[ladder[next_node]],ladder[next_node]});
                } 
            }
            else if(move[next_node]>move[cur_node]+1&&snakeb[next_node]){
                move[next_node]=move[cur_node]+1;
                if(move[snake[next_node]]>move[cur_node]+1){
                move[snake[next_node]]=move[cur_node]+1;
                pq.push({-move[snake[next_node]],snake[next_node]});
                } 
            }
            else if(move[next_node]>move[cur_node]+1){
                 move[next_node]=move[cur_node]+1;
                pq.push({-move[next_node],next_node});
                } 

            }
           }
        }
if(move[100]!=1e9)
        cout<<move[100]<<endl;
        else cout<<-1<<endl;
    }


    
    
    


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}