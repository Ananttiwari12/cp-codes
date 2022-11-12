#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

int dist[1001][1001];
bool visited[1001][1001];
int n,m;

bool isValid(int x, int y){
    if(x<1 or x>n or y<1 or y>m) return false;
    if(visited[x][y]==true) return false;
    return true;
}

int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

void bfs(int srcX, int srcY){
    queue<pair<int,int>>q;
    q.push({srcX,srcY});
    visited[srcX][srcY]=true;
    dist[srcX][srcY]=0;

    while(!q.empty()){
        int currX=q.front().first;
        int currY=q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            if(isValid(currX+dx[i],currY+dy[i])){
                int newX=currX+dx[i];
                int newY=currY+dy[i];

                dist[newX][newY]=dist[currX][currY]+1;
                visited[newX][newY]=true;
                q.push({newX,newY});
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>m;
    int x,y;
    cin>>x>>y;
    bfs(x,y);

    return 0;
}