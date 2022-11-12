#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

const int N=1e6;
vector<int>gr[N];

int visited[N];
void dfs(int source){
    visited[source]=1;
    for(auto child: gr[source]){
        if(!visited[child]){
            dfs(child);
        }
    }
}


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n,m;
    cin>>n>>m;

    for(int i=0; i<m;i++){
        int x,y; cin>>x>>y;
        gr[x].push_back(y);
        gr[y].push_back(x);
    }

    if(m!=n-1) cout<<"NO"<<endl;
    else{
        int cc=0;
        for(int i=1; i<=n;i++){
            if(!visited[i]){
                dfs(i);
                cc++;
            }
            if(cc>1)break;
        }

        if(cc==1)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}