#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>g;
vector<int> col;
vector<int >par;
bool is_cycle=0;
vector<int>any_cycle;
void dfs(int node,int p){
    col[node]=2;
    par[node]=p;
    for(auto v:g[node]){
        if(col[v]==1){
        
            dfs(v,node);
        }
        else if(col[v]==2){
            //code v is back edge
            // we found a cyle
            cout<< node<< "hit"<<endl;
            if(is_cycle==0){
                
                int temp =node;
                while(temp!=v){
                    any_cycle.push_back(temp);
                    temp=par[temp];
                }
                any_cycle.push_back(temp);
                reverse(any_cycle.begin(),any_cycle.end());

            }
            is_cycle=1;
        }
        else if(col[v]==3){
            // cross edge
        }
    }
    col[node]=3;
}

void solve(){
    int n,m;
    cin>>n>>m;
    g.resize(n+1);
    par.resize(n+1);
    col.assign(n+1,1);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
    }
    for(int i=1;i<=n;i++){
        if(col[i]==1) dfs(i,0);
    }
    for(auto v :any_cycle){
        cout<<v<<" ";
    }


}
int main(){
      ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
        solve();
  
    return 0;
}