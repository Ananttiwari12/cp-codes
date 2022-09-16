#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

const int N=1e6;
vector<int>gr[N];
int visited[N];

void bfs(int source){
    queue<int>q;
    q.push(source);
    visited[source]=1;

    while(!q.empty()){
        int f=q.front();
        cout<<f<<" ";
        q.pop();
        for(auto nbr: gr[f]){
            if(!visited[nbr]){
                q.push(nbr);
                visited[nbr]=1;
            }
        }
    }
    
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin>>n;
    for(int i=0; i<n-1;i++){
        int x,y; cin>>x>>y;
        gr[x].push_back(y);
        gr[y].push_back(x);
    }

    bfs(1);
    
    return 0;
}