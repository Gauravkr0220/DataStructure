#include<bits/stdc++.h>
using namespace std ;
 struct node {
    int child [26];
    node(){
        memset(child,-1,sizeof(child));
    }
 };

 struct trie{
    vector<node>nodes;
    trie(){
        node rootnode;
        nodes.push_back(rootnode);
    }
    void insert(string s)
    {
        int cur_node_idx=0;
        for(int i=0;i<s.length();i++){
            if(nodes[cur_node_idx].child[s[i]-'a']==-1){
                node new_node;
                nodes.push_back(new_node);// only pushed
                nodes[cur_node_idx].child[s[i]-'a']=nodes.size()-1;// indicating arrow for new node by index

        }
        cur_node_idx=nodes[cur_node_idx].child[s[i]-'a'];
        }
    }
    int get_node_count(){
        return nodes.size();
    }
 };
 void solve() {
  string s;
  cin>>s;
 trie t;
 for(int i=0;i<s.length();i++){
    t.insert(s.substr(i));
 }
 cout<<t.get_node_count()<<endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}