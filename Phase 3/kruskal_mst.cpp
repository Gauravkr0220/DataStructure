struct UnioFind{
    int n,set_size, *parent,*rank;
    UnioFind(){}
    UnioFind(int a){
        n=set_size=a;
        parent=new int [n+1];
        rank=new int [n+1];
        for(int i=1;i<=n;i++){
            parent[i]=i; rank[i]=1;
        }
    }
    int find(int x){
        if(x!=parent[x]) return parent[x]=find(parent[x]);
        return x;
    }
    void merge(int x,int y){
        int xroot=find(x);
        int yroot=find(y);
        if(xroot!=yroot){
            if(rank[xroot]>=rank[yroot]){
                parent[yroot]=xroot;
                rank[xroot]+=rank[yroot];
            }
            else {
                parent[xroot]=yroot;
                rank[yroot]+=rank[xroot];
            }
            set_size-=1;
        }

    }
    void reset(){
        set_size=n; for(int i=1;i<=n;i++){
            parent[i]=i; rank[i]=1;
        }
    }
    int size(){
        return set_size;
    }
};
vector<pair<int,int>>g[100100];

void solve(){
    int n,m;
    cin>>n>>M;
    int a,b,c;
    UnionFind uf(n);
    vector<pair<int,pair<int,int>>> edgelist;
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        g[a].push_back({b,c});
        g[b].push_back({a,c});
        edgelist.push_back({c,{a,b}});
    }
    int mst_cost=0;
    sort(edgelist.begin(),edgelist.end());
    for(auto v:edgelist){
        int x=v.second.first;
        int y=v.second.second;
        if(uf.find(x)!uf.find(y)){
            mst_cost+=v.first;
            uf.merge(x,y);
        }
    }
    cout<<mst_cost<<endl;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}