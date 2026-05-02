#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod =1e9+7;
vector<int>fact(1000005, 1);
vector<int>invfact(1000005, 1);
int binpow(int a, int b, int mod)
{
    int res=1;
    a%=mod;
    while(b>0)
    {
        if(b&1) res=(res*a)%mod;
        a=(a*a)%mod;
        b>>=1;
    }
    return res;
}
void precompute()
{
    for(int i=2; i<1000005; i++)
    {
        fact[i] = (fact[i-1]*i)%mod;
    }
    
    for(int i=1000004; i>=0; i--)
    {
        invfact[i] = binpow(fact[i], mod-2, mod);
    }
}

void solve()
{
    int a,b;
    cin>>a>>b;
    if(a < b) swap(a, b);
    if(a == 0 && b == 0) {
        cout << "1\n";
        return;
    }
    else{
        int ans= (((fact[a] %mod)* (invfact[a-b] % mod) )%mod* invfact[b] % mod) % mod;
        cout << ans << "\n";
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    precompute();
    int t;
    cin>>t;
    while(t--)
    solve();
    return 0;
}