#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

const int N= 1e6,M=20;

vector<int>gr[N];

int parent[N][M];
int dept[N];


void dfs(int cur, int par){
    dept[cur]=dept[par]+1;

    // creating sparse table
    parent[cur][0]=par;
    for(int j=1; j<M;j++){
        parent[cur][j]=parent[parent[cur][j-1]][j-1];
    }

    for(auto nbr: gr[cur]){
        if(nbr!=par){
            dfs(nbr, cur);
        }
    }
}

int LCA(int u, int v){
    if(dept[u]<dept[v]) swap(u,v); // now u and v are equal
    int diff= dept[u]-dept[v];

    // making u and v on the same level
    for(int j=M-1;j>=0;j--){
            if((diff>>j)&1)
            u=parent[u][j];
        }
        if(u==v)return u;

    for(int j=M-1;j>=0;j--){
        if(parent[u][j]!=parent[v][j]){
            u=parent[u][j];
            v=parent[v][j];
        }
    }
    return parent[u][0];
    //return parent[v][0];
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,q; cin>>n>>q;
    for(int i=1; i<n;i++){
        int x,y;
        cin>>x>>y;
        gr[x].push_back(y);
        gr[y].push_back(x);
    }

    dfs(1,0);
    
    while(q--){

        int a,b;
        cin>>a>>b;
        int lca= LCA(a,b);
        int ans=dept[a]+dept[b]-2*dept[lca];
        cout<<ans<<endl;
    }
    return 0;
    
}