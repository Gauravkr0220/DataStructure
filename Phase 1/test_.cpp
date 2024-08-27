#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int n = s.length();
    map<char, int> hash;
    for(int i=0; i<n; i++){
        hash[s[i]]++;
    }
    int cnt = 0;
    char odd; // the ch which occurs odd times
    for(auto it : hash){
        if((it.second)%2 == 1){
            cnt++;
            char c = it.first;
            odd = c;
        }
    }
   

    if(cnt > 1) cout << "NO SOLUTION";
    else{
        if(cnt==1)
        s[n/2] = odd;
        int j = 0;
        for(auto it : hash){
            for(int i = 0; i < (it.second)/2; i++){
                s[j] = it.first;
                s[n-j-1] =  it.first;
                j++;
            }
        }
        cout<<s<<endl;

    }

    return 0;
}