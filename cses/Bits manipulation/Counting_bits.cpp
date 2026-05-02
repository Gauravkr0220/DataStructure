#include<bits/stdc++.h>
using namespace std;
#define int long long 
void solve()
{
    int x;
    cin>>x;
    x++;
    int ans=0;
    for(int i=0;i<63;i++)
    {
        int temp=(x/(1LL<<(i+1)))* (1LL<<i);
        temp+=max((x%(1LL<<(i+1)))- (1LL<<i),0LL);
        ans+=temp;
    }
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}