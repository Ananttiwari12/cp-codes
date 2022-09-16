#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

const int N=1e6;
vector<int>gr[N], grr[N]; // grr is reverse graph
vector<int>order;
int component[N];
int visited[N];

void dfs1(int cur){
    visited[cur]=1;
    for(auto x: gr[cur]){
        if(!visited[x]) dfs1(x);
    }
    order.push_back(cur);
}

void dfs2(int cur, int comp){
    visited[cur]=1;
    component[cur]=comp;
    for(auto x: grr[cur]){
        if(!visited[x]) dfs2(x,comp);   
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m;  cin>>n>>m;
    for(int i=0; i<m;i++){
        int x,y; cin>>x>>y;
        gr[x].push_back(y);
        grr[y].push_back(x);
    }
    for(int i=1; i<=n; i++){
        if(!visited[i])dfs1(i);
    }
    reverse(order.begin(), order.end());

    // for(auto x: order){
    //     cout<<x<<" ";
    // }

    int comp=1;
    memset(visited,0, sizeof(visited));
    for(auto x: order){
        if(!visited[x])dfs2(x, comp++);
    }
    for(int i=1; i<=n;i++){
        cout<<i<<" "<<component[i]<<" "<<endl;
    }

    cout<<"Total strongly components are--> "<<comp-1<<endl;

    // After that print connected components
    return 0;
}