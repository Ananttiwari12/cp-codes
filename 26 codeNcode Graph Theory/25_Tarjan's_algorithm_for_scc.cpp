#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

const int N=1e5;
vector<int>gr[N];
bool visited[N];
bool onstack[N];
stack<int>st; int timer=1;
int in[N], low[N];
int scc=0;

void dfs(int node){
    visited[node]=true;
    onstack[node]=true;
    st.push(node);
    in[node]=low[node]=timer++;

    for(auto child: gr[node]){
        if((visited[child]==true) and (onstack[child]==true)){
            low[node]=min(low[node], in[child]);
        }

        else
            if(visited[child]==false){
            dfs(child);
            if(onstack[child]==true){
                low[node]=min(low[child],low[node]);
            }
        }
    }

    if(in[node]==low[node]){
        scc++;
        cout<<"Scc #: "<<scc<<endl;
        
        int u;
        while(1){
            u=st.top();
            st.pop(); onstack[u]=false;
            cout<<u<<" ";
            if(u==node)break;
        }
        cout<<endl;
    }

}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m; cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y; cin>>x>>y;
        gr[x].push_back(y);
    }
    
    for(int i=1;i<=n;i++){
        visited[i]=false;
        onstack[i]=false;
    }
    for(int i=1;i<=n;i++){
        if(!visited[i]) dfs(i);
    }
    return 0;
}