#include<bits/stdc++.h>
using namespace std ;
 struct node {
    int child [26];
    int end_count;
    int prefix_count;
    node(){
        memset(child,-1,sizeof(child));
        end_count=0;
        prefix_count=0;
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
        // next node me jane se pehle
        nodes[cur_node_idx].prefix_count++;
        cur_node_idx=nodes[cur_node_idx].child[s[i]-'a'];
        }
        nodes[cur_node_idx].end_count++;
    }
    int get_node_count(){
        return nodes.size();
    }
    void query(string s){

         int cur_node_idx=0;
        for(int i=0;i<s.length();i++){
            if(nodes[cur_node_idx].child[s[i]-'a']==-1){
             cout<<0<<endl;
             return;   

        }
        
        cur_node_idx=nodes[cur_node_idx].child[s[i]-'a'];
        }
        cout<<nodes[cur_node_idx].end_count<<" "<<nodes[cur_node_idx].prefix_count<<endl;
        
    }
 };
 void solve() {
 int n;
 cin>>n;
 trie t;
 for(int i=0;i<n;i++){
    string s;
    cin>>s;

    t.insert(s);
 }
int q;
cin>>q;
while(q--){
    string s1;
    cin>>s1;
    t.query(s1);
}
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}