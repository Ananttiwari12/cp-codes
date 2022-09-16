#include<bits/stdc++.h>
using namespace std;

vector<int> a[100001];
bool vis[100001];
int dis[100001]={-1};
int parent[1000001];

void bfs(int source, int dest=-1){
    queue<int> q;
    q.push(source);
    for(int i=0;i<1000001; i++){
        parent[i]=-1;
    }
    dis[source]=0;
    parent[source]=source;
    vis[source]=1;
    
    while(!q.empty()){
        int node = q.front(); q.pop();
        for(int child: a[node]){
            if(!vis[child]){
                vis[child]=1;
                q.push(child);
                parent[child]=node;
                dis[child]=dis[node]+1;
            }
        }
    }
    if(dis[dest]>0){
        cout<<dis[dest]+1<<endl;
        if(dest!=-1){
            vector<int>res;
            int temp=dest;
            while(temp!=source){
                res.push_back(temp);
                temp=parent[temp];
            }
            res.push_back(source);
            for(int i=res.size()-1;i>=0;i--)
            cout<<res[i]<<" ";
        }
    }
    else if(dis[dest]==0) cout<<"IMPOSSIBLE"<<endl;
  
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m; cin>>n>>m;
    
    for(int i=0 ;i<m; i++){
        int x,y; cin>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    bfs(1,n);
    return 0;
}
