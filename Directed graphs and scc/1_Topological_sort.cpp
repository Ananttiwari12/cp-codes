#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define ll long long

const int N=1e5+1;

vector<int>gr[N];
vector<int>order;

int visited[N];

void dfs(int cur, int par){
    visited[cur]=1;
    for(auto x: gr[cur]){
        if(!visited[x]){
            dfs(x,cur);
        }
    }
    order.push_back(cur);
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m;
    cin>>n>>m;
    for(int i=0; i<m;i++){
        int x,y;
        cin>>x>>y;
        gr[x].push_back(y);
    }
    for(int i=1; i<=n;i++){
        if(!visited[i]){
            dfs(i,0);
        }
    }
    reverse(order.begin(),order.end());

    for(auto x: order)cout<<x<<" ";
    return 0;
}