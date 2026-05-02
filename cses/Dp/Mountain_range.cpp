#include<bits/stdc++.h>
using namespace std;


void solve()
{
    int n;
    cin>>n;
    vector<int>left(n,-1);
    vector<int>right(n,n);
    vector<int>arr;
    for(int i=0;i<n;i++)
    {
        int g; cin>>g; arr.push_back(g);
    }
    for(int i=n-1;i>=0;i--)
    {
        int val=i+1;
        while(val<n&& arr[val]<arr[i]){
            val=right[val];
        }
        right[i]=val;
    }
    for(int i=0;i<n;i++)
    {
        int val=i-1;
        while(val>=0&& arr[val]<arr[i]){
            val=left[val];
        }
        left[i]=val;
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        ans=max({ans,i-left[i]-1,right[i]-i-1});
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