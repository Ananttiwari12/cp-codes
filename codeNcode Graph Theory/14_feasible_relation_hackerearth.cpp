#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

const int N=1e6;
vector<int>gr[N+1];
int visited[N+1];
int ccnodes[N+1];
int cc;

void dfs(int src){
    visited[src]=1;
    ccnodes[src]=cc;
    for(auto child: gr[src]){
        if(!visited[child]){
            dfs(child);
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t; cin>>t;
    while(t--){

        int n,m; cin>>n>>m;
        for(int i=1; i<=n;i++){
            gr[i].clear();
            visited[i]=0;
        }

        vector<pair<int,int>>edgelist;
        for(int i=0; i<m;i++){
        int x,y;
        string s;
        cin>>x>>s>>y;
        if(s=="="){
            gr[x].push_back(y);
            gr[y].push_back(x);
        }
        else{
            edgelist.push_back({x,y});
        }
        }

        for(int i=1; i<=n;i++){
            if(!visited[i]){
                cc++;
                dfs(i);
            }
        }
        bool ok=true;
        for(int i=0; i<edgelist.size();i++){
            int x=edgelist[i].first;
            int y=edgelist[i].second;
            if(ccnodes[x]==ccnodes[y]){
                ok=false;
                break;
            }
        }
        if(ok)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;


    }

    return 0;
}