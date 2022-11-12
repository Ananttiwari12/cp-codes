#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long
const int N=1e5;

vector<int>gr[N];
int visited[N];

void dfs(int source){
    visited[source]=1;
    cout<<source<<" ";
    for(auto child: gr[source]){
        if(!visited[child]){
            dfs(child);
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
    int cc=0;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            dfs(i);
            cc++;
            cout<<endl;
        }
    }
    cout<<"No of connected components are: "<<cc;
    return 0;
}