#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<int> mergesort(int i,int j,vector<int>&a)
{
   if(i==j) return {a[i]};
   int mid=(i+j)/2;
   vector<int>left=mergesort(i,mid,a);
   vector<int>right=mergesort(mid+1,j,a);
   vector<int>merged;
   int l=0,r=0;
   while(l<left.size() && r<right.size())
   {
       if(left[l]<=right[r])
       {
           merged.push_back(left[l]);
           l++;
       }
       else
       {
           merged.push_back(right[r]);
           r++;
       }
   }
   if(l<left.size())
   {
       while(l<left.size())
       {
           merged.push_back(left[l]);
           l++;
       }
   }
   else if(r<right.size())
   {
       while(r<right.size())
       {
           merged.push_back(right[r]);
           r++;
       }
   }
   return merged;
}
void solve(){
   int n;
   cin>>n;
   vector<int>a(n);
   for(int i=0;i<n;i++) cin>>a[i];

  vector<int>ans= mergesort(0,n-1,a);
   for(int i=0;i<n;i++) cout<<ans[i]<<" ";
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    solve();
    return 0;
}