
// CSES shortest routes 1

#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long
#define INF 1e18

int n,m,q;

vector<vector<int>> floyd_warshall(vector<vector<int>>graph){

    vector<vector<int>>dist(graph);

    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){

                if(dist[i][j]>dist[i][k]+dist[k][j])
                dist[i][j]=dist[i][k]+dist[k][j];
            }
        }
    }
    return dist;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    cin>>n>>m>>q;
    
    vector<vector<int>>gr(n+1, vector<int>(n+1, INF));

    for(int i=0;i<=n;i++){
        gr[i][i]=0;
    }

    for(int i=0;i<m;i++){
        int x,y,w; cin>>x>>y>>w;
        gr[x][y]=min(w,gr[x][y]);
        gr[y][x]=min(w,gr[y][x]);
        
    }

    auto res=floyd_warshall(gr);

    while(q--){
        int x,y; cin>>x>>y;
        if(res[x][y]==1e18)cout<<-1<<endl;
        else cout<<res[x][y]<<endl;
    }

    return 0;
}