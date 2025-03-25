
#include <bits/stdc++.h>
using namespace std;
using ll = long long ;
int dp[1010][1010];
 int rec(int x,int y){
    if(x==0&&y==0){
        return 0;// no stone to take
    }
    if(dp[x][y]!=-1) return -1;
    int ans=0;
    for(int z=0;z<x;z++){
        if(rec(z,y)==0){
            ans=1;
            break;
        }
    }
    for(int z=0;z<y;z++){
        if(rec(x,z)==0){
            ans=1;
            break;
        }
    }
    for(int z=1;z<min(x,y);z++){
        if(rec(x-z,y-z)==0){
            ans=1;
            break;
        }
    }
    return dp[x][y]=ans;

 }
void solve() {
   int a,b;
   cin>>a>>b;
   //Recusion
//    memset(dp,-1,sizeof(dp) );
//    cout<<rec(a,b)<<endl;
    
for(it x=0;x<=a,x++){
    for(int y=0;y<=b;y++){
        if(x==0&&y==0){
            dp[x][y]= 0;// no stone to take
        }
        int ans=0;
        for(int z=0;z<x;z++){
            if(dp[z][y]==0){
                ans=1;
                break;
            }
        }
        for(int z=0;z<y;z++){
            if(dp[x][z]==0){
                ans=1;
                break;
            }
        }
        for(int z=1;z<min(x,y);z++){
            if(d[x-z][y-z]==0){
                ans=1;
                break;
            }
        }
        dp[x][y]=ans;
    }
}
cout<<dp[x][y]<<endl;

}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}