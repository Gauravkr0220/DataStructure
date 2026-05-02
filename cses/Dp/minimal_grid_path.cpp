#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    vector<vector<char>>grid;
    grid.resize(n, vector<char>(n));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
        char c; cin>>c; grid[i][j]=c;
    }
    queue<pair<char,pair<int,int>>>q;
    vector<vector<bool>>visited(n, vector<bool>(n, false));
    string ans="";
    q.push({grid[0][0], {0, 0}});
    visited[0][0] = true;
    while(!q.empty())
    {
      int sz=q.size();
      vector<pair<char,pair<int,int>>>temp;
      int ch[26];
        memset(ch, 0, sizeof(ch));
      for(int i=0;i<sz;i++)
      {
        auto it=q.front();
        q.pop();
        int c=it.first;
        ch[c-'A']++;
        temp.push_back(it);
      }
      char l;
      for(int i=0;i<26;i++)
      {
        if (ch[i]>0)
        {
          ans+=char(i+'A');
          l=char(i+'A');
          break;
        }
      }
      for(int i=0;i<temp.size();i++)
      {
        if(temp[i].first==l)
        {
          int x=temp[i].second.first;
          int y=temp[i].second.second;
          if(x+1<n && y<n&& !visited[x+1][y]) {q.push({grid[x+1][y], {x+1, y}});   visited[x+1][y] = true;}
          if(y+1<n && x<n&&!visited[x][y+1]) {q.push({grid[x][y+1], {x, y+1}}); visited[x][y+1] = true;}
          
        }
      }
        
    }
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}