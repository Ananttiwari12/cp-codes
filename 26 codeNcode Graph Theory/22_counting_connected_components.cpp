/*
0 0 1 0 1 1
0 1 1 0 0 1
0 1 0 0 0 0
1 0 1 1 0 0   <--- Grid
0 0 0 1 0 0
0 1 1 0 1 1
*/

#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

int x,y;
int n,m;
bool visited[1001][1001];
int gr[1001][1001];

bool isValid(int x, int y){
    if(x<1 or x>n or y<1 or y>m) return false;
    if(visited[x][y]==true or gr[x][y]==0) return false;
    return true;
}

int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

void dfs(int x, int y){
    visited[x][y]=true;

    for(int i=0; i<4 ;i++){
    if(isValid(x+dx[i],y+dy[i]))
        dfs(x+dx[i],y+dy[i]);
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n>>m;

    for(int i=1; i<=n;i++){
        for(int j=1; j<=m;j++){
            cin>>gr[i][j];
        }
    }
    int cc=0;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(!visited[i][j] and gr[i][j]==1){
                cc++;
                dfs(i,j);
            }
        }
    }
    cout<<"total connected components are : "<<cc<<endl;

    return 0;
}