#include <bits/stdc++.h>
int n;
using namespace std;
int queen[20];// where is my queen in ith row
bool check(int row,int col){
     for(int i=0;i<row;i++){
        int prow=i;
        int pcol=queen[i];
        if(pcol==col|| abs(pcol-col)==abs(prow-row)) return 0;
     }
     return 1;
}
int rec(int level){
    if(level==n) return 1;
    int ans=0;
    for(int col=0;col<n;col++){
        if(check(level,col)){
            queen[level]=col;
            ans+=rec(level+1);
            queen[level]=-1;
        }
    }
    return ans;
}
void solve() {
    cin>>n;
    memset(queen,-1,sizeof(queen));
    int ans=rec(0);
    cout<<ans<<endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}