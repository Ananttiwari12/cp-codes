#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

const int N=1e5;
vector<int>gr[N];
int visited[N];
int in[N];
int out[N];

int timer=1;

void dfs(int source){
    visited[source]=1;
    in[source]=timer++;
    for(auto child: gr[source]){
        if(!visited[child]){
            dfs(child);
        }
    }
    out[source]=timer++;
}


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m; cin>>n>>m;
    for(int i=0; i<m;i++){
        int x,y;
        cin>>x>>y;
        gr[x].push_back(y);
        gr[y].push_back(x);
    }
    dfs(1);
    int q; cin>>q;
    while(q--){

        int x; cin>>x;
        int cnt=0;
        for(int i=1; i<=n;i++){
            if(in[i]>=in[x] and out[i]<=out[x])cnt++;
        }
        cout<<cnt<<endl;
    }
    return 0;
}