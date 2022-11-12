#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define ll long long

const int N=1e5+1;

vector<int>gr[N];

bool vis[N];
bool cycle=false;

void DFS(int cur, int par){
    cout<<cur<<endl;
    vis[cur]=true;
    for(auto x: gr[cur]){
        if(!vis[x]){
            DFS(x,cur);
        }
        // backedge case
        else if(x!= par){
            // backedge
            // cout<<cur<<" "<<x<<endl;
            cycle=true;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m;
    cin>>n>>m;
    
    for(int i=0; i<m; i++){
        int x,y;
        cin>>x>>y;
        gr[x].push_back(y);
        gr[y].push_back(x);
    }

    for(int i=1; i<=n; i++){
        if(!vis[i]){
            DFS(i,0);
        }
    }
    if(cycle){
        cout<<"YES cycle found";
    }
    else{
        cout<<"Cycle not found";
    }
    
    return 0;
}