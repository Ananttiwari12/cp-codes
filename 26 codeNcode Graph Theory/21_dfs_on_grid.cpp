#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

int x,y;
int n,m;
bool visited[1001][1001];

bool isValid(int x, int y){
    if(x<1 or x>n or y<1 or y>m) return false;
    if(visited[x][y]==true) return false;
    return true;
}

int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

void dfs(int x, int y){
    visited[x][y]=true;
    cout<<x<<" "<<y<<endl;

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
    dfs(1,1);

    return 0;
}