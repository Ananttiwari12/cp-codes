#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

const int N=1e6;
vector<int>gr[N];
int visited[N];
int dist[N];
int distfromsrc[N];

void bfs(int src){
    queue<int>q;
    q.push(src);
    visited[src]=1;
    dist[src]=0;

    while(!q.empty()){
        int f= q.front();
        q.pop();
        for(auto nbr: gr[f]){
            if(!visited[nbr]){
                q.push(nbr);
                visited[nbr]=1;
                dist[nbr]=dist[f]+1;
                distfromsrc[dist[nbr]]++;
            }
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m; cin>>n>>m;
    for(int i=0;i<=n;i++){
        visited[i]=0;
        gr[i].clear();
        dist[i]=0;
    }

    for(int i=0;i<m;i++){
        int x,y; cin>>x>>y;
        gr[x].push_back(y);
        gr[y].push_back(x);
    }

    int q;cin>>q;
    while(q--){
        
        for(int i=0;i<=n;i++){
            distfromsrc[i]=0;
            visited[i]=0;
        }
        int src,d;
        cin>>src>>d;
        bfs(src);
        cout<<distfromsrc[d]<<endl;
    }
    return 0;
}