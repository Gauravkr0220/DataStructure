#include<bits/stdc++.h>
using namespace std;
vector<int>g[100100];
int indp[100100];
int outdp[100100];
int ans[100100];
void dfsin(int node,int par){
    //initialised it as leaf
    indp[node]=0;

    for(auto ch:g[node]){
        if(ch!=par){
        dfs(ch,node);
    indp[node]=max(indp[ch]+1,indp[node]);
}
    }
}
// out dp ch node got value form parent
void dfsout(int node,int par,int outVal){
    outdp[node]=outVal;
    int max1=-1,int max2=-1;
    for(auto ch:g[node]){
        if(ch!=par){
            if(indp[ch]>max1) {
                max2=max1;
                max1=indp[ch];
            }
            else if(indp[ch]>max2){
                max2=indp[ch];
            }
}

    }
    for(auto ch:g[node]){
        int (ch!=par){
            if(indp[ch]==max1){// as rooted a one node so every node have distinct value
                dfsout(ch,node,max(max2+2,outdp[node]+1));
            }
            else {
                dfsout(ch,node,max(max1+2,outdp[node]+1));
            }
        }
    }
}
void solve(){
    //take graph as input
    dfsin(1,0);
    dfsout(1,0,0);
    for(int i=1;i<=n;i++){
        ans[i]=max(indp[i],outdp[i]);
        cout<<ans[i]<<end;
    }
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}