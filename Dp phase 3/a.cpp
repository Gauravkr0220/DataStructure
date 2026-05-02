
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
int dp[1001][1001];
int done[1001][1001];
string str3="";
bool flag=false;
int rec(int i,int j,string &str1, string &str2){
    int n=str1.size();
    int m=str2.size();
    if(flag) return 1e9;
    if(i>n||j>m) return 1e9;
    if(i==n&&j==m) {
        flag=true;
        return 0;
    }
    if(dp[i][j]!=-1) return dp[i][j]; 
    int ans=1e9;
    if(str1[i]==str2[j]){
        if(rec(i+1,j+1,str1,str2)+1<ans){
            ans=rec(i+1,j+1,str1,str2)+1;
            done[i][j]=1;
        }
    }
    else{
        if(rec(i+1,j,str1,str2)+1<ans){
            ans=rec(i+1,j,str1,str2)+1;
            done[i][j]=2;
        }
        if(rec(i,j+1,str1,str2)+1<ans){
            ans=rec(i,j+1,str1,str2)+1;
            done[i][j]=3;
        }
    }
    return dp[i][j]=ans;
   

}
void generate(int i,int j,string &str1, string &str2){
    int n=str1.size();
    int m=str2.size();
    
    if(i>n||j>m) return ;
    if(i==n&&j==m) {   
        return;
    }
    int x=done[i][j];
    if(x==1){
        str3+=str1[i];
        generate(i+1,j+1,str1,str2);
    }
    else if(x==2){
            str3+=str1[i];
        generate(i+1,j,str1,str2);
    }
    else if(x==3){
            str3+=str2[j];
        generate(i,j+1,str1,str2);
    }


}
string ShortestCommonSupersequence(string &str1, string &str2) {
    str3="";
    flag=false;
    for(int i=0;i<str1.size();i++){
        for(int j=0;j<str2.size();j++){
            dp[i][j]=-1;
            done[i][j]=0;
        }
    }
    int ans=rec(0,0,str1,str2);
     generate(0,0,str1,str2);
     cout<<str3<<endl;
 return str3;
}
























void checker() {
    string x, y;
    cin >> x >> y;
    auto s = ShortestCommonSupersequence(x, y);
    cout << s.size() << endl;
    bool f = 1;
    int i = 0, j = 0;
    while (i < x.size() && j < s.size()) {
        if (x[i] == s[j])i++, j++;
        else j++;
    }
    if (i != x.size())f = 0;
    i = 0, j = 0;
    while (i < y.size() && j < s.size()) {
        if (y[i] == s[j])i++, j++;
        else j++;
    }
    if (i != y.size())f = 0;
    cout << f << endl;
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

#ifdef Mastermind_
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    // int i = 1;
    cin >> t;
    while (t--) {
        // cout << "Case #" << i << ": ";
        checker();
        // i++;
    }
    return 0;
}
