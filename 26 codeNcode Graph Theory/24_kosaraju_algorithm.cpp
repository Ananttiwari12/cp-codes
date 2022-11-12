#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

const int N=1e5;
vector<int>gr[N],tgr[N]; // here tgr is transpose graph
int visited[N];
vector<int>order;
vector<int>scc;

void dfs1(int src){
    visited[src]=1;
    for(auto child: gr[src]){
        if(!visited[child]){
            dfs1(child);
        }
    }
    order.push_back(src);
}

void dfs2(int src){
    visited[src]=1;
    for(auto child: tgr[src]){
        if(!visited[child]){
            dfs2(child);
        }
    }
    scc.push_back(src);
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin>>t;
    while(t--){

        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            gr[i].clear();
            tgr[i].clear();
            visited[i]=0;
        }
        order.clear();
        for(int i=0;i<m;i++){
            int a,b; cin>>a>>b;
            gr[a].push_back(b);
            tgr[b].push_back(a);
        }

        for(int i=1;i<=n;i++){
            if(!visited[i]){
                dfs1(i);
            }
        }
        for(int i=1;i<=n;i++){
            visited[i]=0;
        }

        for(int i=1;i<=n;i++){
            if(visited[order[n-i]]==0){
                scc.clear();
                dfs2(order[n-i]);
            cout<<"dfs2 called from "<<order[n-i]<<": printing scc "<<endl;
            for(auto node: scc){
                cout<<node<<" ";
            }
            cout<<endl;
            }
        }
    }
    return 0;
}