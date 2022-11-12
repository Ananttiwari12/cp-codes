#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

const int N=1e6;
vector<int>gr[N];
int visited[N];
int subsize[N]={0};

int dfs(int source){

    visited[source]=1;
    int current_node_size=1;

    for(auto child: gr[source]){
        if(!visited[child]){
            current_node_size+= dfs(child);
        }
    }
    subsize[source]=current_node_size;
    return current_node_size;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin>>n;

    for(int i=0; i<n-1;i++){
        int x,y;
        cin>>x>>y;
        gr[x].push_back(y);
        gr[y].push_back(x);
    }
    dfs(1);

    
    for(int i=1; i<=n;i++){
        cout<<"size of subtrees of "<<i<<" is-->"<<subsize[i]<<endl;
    }


    return 0;
}