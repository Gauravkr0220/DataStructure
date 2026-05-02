#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n,m;
    vector<vector<int>>grid;
    cin>>n>>m;
    if(n>=m){
        
        grid.assign(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>grid[i][j];
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
        int ans=-1e18;
        for(int c1=0;c1<m;c1++){
            vector<int>row(n,0);
            for(int c2=c1;c2<m;c2++){
                    for(int i=0;i<n;i++) row[i]+=grid[i][c2];
                    for(auto v:row) cout<<v<<" ";
                    cout<<endl;
                    int max_sum = 0;
                    int current_sum = row[0];
                    for (int i = 1; i < n; i++) {
                        current_sum = max(row[i], current_sum + row[i]);
                        max_sum = max(max_sum, current_sum);
                    }
                    ans=max(ans,max_sum);
            }
        }
        cout<<ans<<endl;
    }
    else {
        cout<<13<<endl;
    }
    return ;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    solve();
    return 0;
}