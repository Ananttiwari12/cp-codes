#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

const int N=1e5;
vector<int>gr[N];
int parent[N];
int visited[N];

bool dfs(int source, int par){
    visited[source]=1;
    for(auto child: gr[source]){
        if(!visited[child]){
            if(dfs(child,source)==true)return true;
        }
        else{
            if(par!=child)return true;
        }
    }
    return false;
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
    if(dfs(1,0))cout<<"contains cycle";
    else cout<<"does not contain cycle";
    
    return 0;
}