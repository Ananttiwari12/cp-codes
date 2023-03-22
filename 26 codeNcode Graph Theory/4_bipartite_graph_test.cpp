#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

const int N=1e6;
vector<int>gr[N];
int visited[N];
int color[N];

bool dfs(int source, int c){
    visited[source]=1;
    color[source]=c;
    
    for(auto child : gr[source]){
        if(!visited[child]){
            if(dfs(child, c^1)==false)return false;
        }
        if(color[source]==color[child])return false;
    }
    return true;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m; cin>>n>>m;
    for(int i=0; i<m;i++){
        int x,y; cin>>x>>y;
        gr[x].push_back(y);
        gr[y].push_back(x);
    }
    if(dfs(1,0))cout<<"Not bipartite";
    else cout<<"bipartite";
    
    return 0;
}