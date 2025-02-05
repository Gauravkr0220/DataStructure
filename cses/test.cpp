#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin>>n;
        vector<int>vec;
        int sum=0;
        for(int i=0;i<n;i++){
            int g; cin>>g;
            sum+=g;
            vec.push_back(g);
        }
        if(sum%n!=0){
            cout<<"NO"<<endl;
            
        }
        else{int c=sum/n;
       
            for(int i=1;i<n-1;i++){
            if(vec[i-1]>c&&vec[i+1]<=c){
                vec[i+1]+=vec[i-1]-c;
                vec[i-1]=c;
            }
            else if(vec[i-1]<c&&vec[i+1]>=c){
                vec[i+1]-=abs(vec[i-1]-c);
                vec[i-1]=c;
            }
        }
        int cnt=0;
         for(int i=0;i<n;i++)
         {
            if(vec[i]==c) cnt++;
         }
         if(cnt==n) cout<<"YES"<<endl;
         else  cout<<"NO"<<endl;


        }
        
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
   
    solve();
    return 0;
}
