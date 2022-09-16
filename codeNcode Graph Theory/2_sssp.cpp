//This algorithm works only for trees
#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

const int N=1e5;
vector<int>gr[N];
int visited[N];
int Distance[N];

void dfs(int source, int dist){
    visited[source]=1;
    Distance[source]=dist;
    for(auto child: gr[source]){
        if(!visited[child]){
            dfs(child,Distance[source]+1);
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin>>n;

    for(int i=0 ;i<n-1;i++){
        int x,y;
        cin>>x>>y;
        gr[x].push_back(y);
        gr[y].push_back(x);
    }
    
    dfs(1,0);
    int q; cin>>q;
    while(q--){

    int desti; cin>>desti;
    cout<<Distance[desti]<<" ";
    }
    return 0;
}