#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long
const int N=1e6;
vector<int>gr[N];
int visited[N];
int distan[N];

void bfs(int source){
    queue<int>q;
    q.push(source);
    visited[source]=1;
    distan[source]=0;
    while(!q.empty()){
        int f=q.front();
        q.pop();
        for(auto nbr: gr[f]){
            if(!visited[nbr]){
                q.push(nbr);
                visited[nbr]=1;
                distan[nbr]=distan[f]+1;
            }
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t; cin>>t;
    while(t--){
    int n,m; cin>>n>>m;
    for(int i=1; i<=n;i++){
        visited[i]=0;
        gr[i].clear();
    }
    for(int i=0; i<m;i++){
        int x,y; cin>>x>>y;
        gr[x].push_back(y);
        gr[y].push_back(x);
    }
    bfs(1);
    cout<<distan[n]<<endl;
    }
    return 0;
}