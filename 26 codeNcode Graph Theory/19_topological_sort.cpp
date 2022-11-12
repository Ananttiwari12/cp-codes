#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

const int N=1e5;
vector<int>gr[N];
int in[N];
vector<int>res;

void kahns(int n){
    queue<int>q;
    for(int i=1;i<=n;i++){
        if(in[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int curr=q.front();
        res.push_back(curr);
        q.pop();
        for(auto node: gr[curr]){
            in[node]--;
            if(in[node]==0){
                q.push(node);
            }
        }
    }
    cout<<"Topological sort: "<<endl;
    for(auto node:res){
        cout<<node<<" ";
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n,m; cin>>n>>m;
    for(int i=1;i<=m;i++){
        int x,y; cin>>x>>y;
        gr[x].push_back(y);
        in[y]++;
    }
    kahns(n);
    return 0;
}