// x time and k slot 
#include <bits/stdc++.h>
int n;
int t[1001];
int s[1001];
int x,k;
int taken[1001];
bool check(int level){
    int timetaken=0;
    int itemtaken=0;
    for(int i=0;i<level;i++){
        if(taken[i]){
            timetaken+= t[i];
            itemtaken+=1;
        }
    }
    timetaken+=t[level];
    itmetaken++;
    if(itemtaken<=x &&itemtaken<=k){
        return 1;
    }
    else return 0;
}
using namespace std;
// here one more less complex code where argument is level, itemtaken, timetaken
int rec(int level){ // max skill i can make from [level ... n-1]
    // level -> current item in[o ... n-1]
    if(level==n) return 0;// aszero indexing;
    // choice to take or not
    // don't take 
    int ans=rec(level+1);
    if(check(level)){
        taken[level]=1;
       ans= max (ans,s[level]+rec(level+1));
        taken[level]=0;
    }
    return ans;

}
void solve() {
    cin>>n;
   for(int i=0;i<n;i++){
    cin>>t[i]>>s[i];
   }
   cin>>x>>k;
   cout<<rec(0)<<endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}