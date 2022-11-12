#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

const int N=1e6;
vector<int>gr[N];
int parent[N];
int dist[N];

int vis[N];

void dfs(int cur, int par){
    dist[cur]=1;
    parent[cur]=par;
    for(auto x: gr[cur]){
        if(x!=par){
            dfs(x,cur);
            dist[x]+=dist[cur];
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,qu; cin>>n>>qu;

    for(int i=0;i<n-1;i++){
        int x,y; cin>>x>>y;
        gr[x].push_back(y);
        gr[y].push_back(x);
    }

    while(qu--){
        int q; cin>>q;
        int a=1;
        dfs(q,-1);
        cout<<dist[q]<<endl;
    }
    return 0;
}