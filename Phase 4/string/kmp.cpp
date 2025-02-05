// https://maang.in/problems/Even-and-Odd-Queries-405?resourceUrl=cs99-cp559-pl3763-rs405&returnUrl=/courses/Premium-Day-Wise-Course-99?tab=chapters
#include <bits/stdc++.h>
using namespace std;
#define int long long


void solve() {
  string s;
  cin>>s;
  int n= s.length();
  int kmp[n+1];
  int i=0;int j=-1;
  kmp[0]=-1;
    while(i<n){
        while(j!=-1&& s[i]!=s[j]) j=kmp[j];
        j++;
        i++;
        kmp[i]=j;
    }

    for(int i=0;i<=n;i++){
        cout<<kmp[i]<<" ";
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
