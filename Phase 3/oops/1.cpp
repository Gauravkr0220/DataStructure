

#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>g;
vector<int> col;

bool is_cycle=0;
vector<int>any_cycle;
using ll=long long;
vector<vector<ll>>dis;
vector<vector<ll>>par;

void solve(){
    int n,m;
    cin>>n;
    dis.assign(n+1,vector<ll>(n+1,1e9));
     par.resize(n+1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
        ll a;
        cin>>a;
        dis[i][j]=min(dis[i][j],a);
    }}
   

   for(int i=1;i<=n;i++){
    par[i].assign(n+1,i);
        
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dis[i][j]>dis[k][j]+dis[i][k]){
                    dis[i][j]=dis[k][j]+dis[i][k];
                    par[i][j]=par[k][j];
                    cout<<i<<' '<<j<<' '<<k<<endl;
                    for(int l=1;l<=n;l++){
            for(int m=1;m<=n;m++){
                cout<<dis[l][m]<<' ';
     
                }
                cout<<endl;}
            //     for(int l=1;l<=n;l++){
            // for(int m=1;m<=n;m++){
            //     cout<<par[l][m]<<' ';
     
            //     }
            //     cout<<endl;}
                }
                }
                
              
            }
        }
    }




int main(){
      ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
        solve();
  
    return 0;
}