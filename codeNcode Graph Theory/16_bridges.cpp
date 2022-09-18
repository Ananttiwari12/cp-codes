#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

const int N=1e6;
vector<int>gr[N];
int visited[N];
int in[N],low[N];
int timer;

void dfs(int src, int par){

    visited[src]=1;
    in[src]= timer;
    low[src]= timer;

    timer++;

    for(auto child: gr[src]){

        if(child==par)continue;
        if(visited[child]){
            //edge node-- child is a back edge
            low[src]=min(low[src],in[child]);
        }
        else{
            //edge ndoe-- child is a forward edge
            dfs(child,src);
            if(low[child]>in[src]){
                cout<<src<<"->"<<child<<" is a bridge"<<endl;
            }
                low[src]= min(low[src],low[child]);
        }
    }
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
    dfs(1,-1);

    return 0;
}