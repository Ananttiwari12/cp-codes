// https://codeforces.com/problemset/problem/500/A
// new year transportation

#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long
const int N=1e6;
vector<int>gr[N];
int visited[N];
int dist[N]={-1};

void dfs(int src, int dist_){
    visited[src]=1;
    dist[src]=dist_;

    for(auto child: gr[src]){
        if(!visited[child]){
            dfs(child,dist[src]+1);
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
        int n,k; cin>>n>>k;
        int a[n-1];
        for(int i=0;i<n-1;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n;i++){
            gr[i].clear();
            visited[i]=0;
            dist[i]=-1;
        }

        for(int i=1;i<=n-1;i++){
            int x=i;
            int y=i+a[i-1];
            gr[x].push_back(y);
        }

        dfs(1,0);
        if(dist[k]!=-1){
            cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl;
    return 0;
}