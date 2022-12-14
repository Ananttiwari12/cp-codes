#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

const int N=1e6;
vector<int>gr[N];
int visited[N];
int cc_size;

void dfs(int source){
    visited[source]=1;
    cc_size++;
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

    int t; cin>>t;
    while(t--){

        int n,m; cin>>n>>m;
        for(int i=0; i<n;i++){
            gr[i].clear();
            visited[i]=0;
        }
        for(int i=0; i<m;i++){
            int x,y;
            cin>>x>>y;
            gr[x].push_back(y);
            gr[y].push_back(x);
        }
        int cc=0;
        cc_size=0;
        int ans=0;
        vector<int>res;
        for(int i=0; i<n;i++){
            if(!visited[i]){
                dfs(i);
                cc++;
                // ans=(ans*cc_size);
                // res.push_back(cc_size);
            }
            if(cc_size!=0)
            res.push_back(cc_size);
            cc_size=0;
        }
        // cout<<cc<<" "<<ans<<endl;

        for(int i=0; i<res.size()-1;i++){
        for(int j=i+1;j<res.size();j++){
            ans+=(res[i]*res[j]);

        }
        }
        cout<<ans<<endl;
    }
    
    return 0;
}