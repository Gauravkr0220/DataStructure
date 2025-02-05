#include<bits/stdc++.h>
using namespace std ;
 struct node {
    int child [26];
    int end_count;
    int prefix_count;
    vector<int>matching;
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
    void insert(string s,int str_id)
    {
        int cur_node_idx=0;
        for(int i=0;i<s.length();i++){
            if(nodes[cur_node_idx].child[s[i]-'a']==-1){
                node new_node;
                nodes.push_back(new_node);// only pushed
                nodes[cur_node_idx].child[s[i]-'a']=nodes.size()-1;// indicating arrow for new node by index

        }
        // next node me jane se pehle
        if(nodes[cur_node_idx].matching.size()<=3){
           nodes[cur_node_idx].matching.push_back(str_id); 
        }
        nodes[cur_node_idx].prefix_count++;
        cur_node_idx=nodes[cur_node_idx].child[s[i]-'a'];
        }
        if(nodes[cur_node_idx].matching.size()<=3){
           nodes[cur_node_idx].matching.push_back(str_id); 
        }
        nodes[cur_node_idx].end_count++;
    }
    int get_node_count(){
        return nodes.size();
    }
    void dfs(int node_idx,string& cur_string){
        if(nodes[node_idx].end_count){
            cout<<cur_string<<endl;
        }
        for(int i=0;i<26;i++){
            if(nodes[node_idx].child[i]!=-1){
                cur_string+=char('a'+i);
                dfs(nodes[node_idx].child[i],cur_string);
                cur_string.pop_back();
            }
        }
    }
    void query(string s,vector<string>text){

         int cur_node_idx=0;
        for(int i=0;i<s.length();i++){
            if(nodes[cur_node_idx].child[s[i]-'a']==-1){
             cout<<0<<endl;
             return;   

        }
        
        cur_node_idx=nodes[cur_node_idx].child[s[i]-'a'];
        }
        cout<<nodes[cur_node_idx].end_count<<" "<<nodes[cur_node_idx].prefix_count<<endl;
        // dfs(cur_node_idx,s);
        for(auto v: nodes[cur_node_idx].matching){
            cout<<text[v]<<endl;
        }
    }
 };
 void solve() {
 int n;
 cin>>n;
 trie t;
 vector<string>text;
 for(int i=0;i<n;i++){
    string s;
    cin>>s;
text.push_back(s);
   
 }
 sort(text.begin(),text.end());
 for(int i=0;i<n;i++){
    t.insert(text[i],i);
 }
int q;
cin>>q;
while(q--){
    string s1;
    cin>>s1;
    t.query(s1,text);
}
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}