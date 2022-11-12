// cses
#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

const int N=1e6;
vector<int>gr[N+1];
int visited[N+1];
vector<int>cycle;

bool dfs(int src, int par){
    visited[src]=1;
    cycle.push_back(src);
    for(auto child:gr[src]){
        

        if(visited[child]!=1){
            if(dfs(child,src)==true)return true;
        }
        else{
            if(child!=par){
                cycle.push_back(child);
                return true;
            }
        }
    }
        cycle.pop_back();
        return false;
}


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m; cin>>n>>m;


    for(int i=1;i<=n;i++){
        visited[i]=0;
        gr[i].clear();
    }
    cycle.clear();

    int cntref=0;
    int dfsref;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        if(cntref==0){
            cntref++;
            dfsref=x;
        }
        gr[x].push_back(y);
        gr[y].push_back(x);
    }



    if(dfs(3,0)){
        vector<int>ans;
        int cnt=0;
        for(int i=cycle.size()-1; i>=0; i--){
            ans.push_back(cycle[i]);
            if(cycle[i]==cycle[cycle.size()-1] and i!=cycle.size()-1){
                break;
            }
    }

    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    }


    else cout<<"IMPOSSIBLE\n";
    
    return 0;
}