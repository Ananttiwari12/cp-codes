#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

const int N=1e6;
vector<int>gr[N];
int in[N];
vector<int>res;

bool kahns(int n){
    priority_queue<int,vector<int>,greater<int>>pq;
    for(int i=1;i<=n;i++){

        if(in[i]==0) pq.push(i);
    }
    while(!pq.empty()){
        int f=pq.top();
        res.push_back(f);
        pq.pop();
        for(auto node: gr[f]){
            in[node]--;
            if(in[node]==0){
                pq.push(node);
            }
        }
    }
    return res.size()==n;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m; cin>>n>>m;
    for(int i=1; i<=m;i++){
        int x,y; cin>>x>>y;
        gr[x].push_back(y);
        in[y]++;
    }

    if(!kahns(n))cout<<"Sandro fails.";
    else{ 
        for(auto node: res){
            cout<<node<<" ";
        }
    }

    return 0;
}