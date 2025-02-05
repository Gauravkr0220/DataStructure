#include <bits/stdc++.h>
using namespace std;

void solve() {
    int t;
    cin >> t;
    while (t--) {
        string n;
        cin >> n;
        int sum = 0;
        bool hasThree = false;
        int two=0;
        int three=0;
        for (char c : n) {
            int digit = c - '0';
            
            sum += digit;
            if(c=='2') two++;
            if(c=='3') three++;
        }
        int l;
        cout<<sum<<endl;
         l=9-(sum%9);
    
    if(three==n.size()) {
        hasThree=true;
    }
        else if(l==0||l==9){
            hasThree=true;
        }
        else if(l==1&&l==3&&l==5&&l==7){
            hasThree=false;
        
        }
        else if(l==2&&two>=1) hasThree=true;
        else if(l==4&&two>=2) hasThree=true;
        else if(l==6&&(two>=3||three>=1)) hasThree=true;
        else if(l==8&&((two>=4)||(two>=1&&three>=1))) hasThree=true;
        
        
        if(hasThree)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
   
    solve();
    return 0;
}
