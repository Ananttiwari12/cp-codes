#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

const int N=1e6;
vector<int>gr[N];
int visited[N];
int helper_node;
int max_dis=-1;
int dist[N];

void dfs_helper(int source, int dist_){
    dist[source]=dist_;
    visited[source]=1;
    if(dist_>max_dis){
        helper_node=source;
        max_dis=dist_;
    }
    for(auto child: gr[source]){
        if(!visited[child]){
            dfs_helper(child,dist[source]+1);
        }
    }
}

void dfs(int source, int par){
    dist[source]=par;
    visited[source]=1;
    for(auto child: gr[source]){
        if(!visited[child]){
            dfs(child,dist[source]+1);
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin>>n;
    for(int i=0;i<n-1;i++){
        int x,y;
        cin>>x>>y;
        gr[x].push_back(y);
        gr[y].push_back(x);
    }
    
    dfs_helper(1,0);
    for(int i=1;i<=n;i++){
        dist[i]=0;
        visited[i]=0;
    }
    dfs(helper_node,0);

    int ans=0;
    // for(int i=1;i<=n;i++){
    //     cout<<dist[i]<<" ";
    // }
    for(int i=1;i<=n;i++){
        ans=max(ans,dist[i]);
    }
    cout<<ans<<endl;
    return 0;
}