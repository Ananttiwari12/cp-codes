#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

const int N=1e5;
vector<int>gr[N];
int visited[N];
int in[N];
int out[N];

int timer=1;

void dfs(int source){
    visited[source]=1;
    in[source]=timer++;
    for(auto child: gr[source]){
        if(!visited[child]){
            dfs(child);
        }
    }
    out[source]=timer++;
}

vector<int> subtreeProblem (int n, vector<vector<int>> edges, vector<int> queries){

    vector<int>res;
    for(int i=0; i<n-1;i++){
        int x,y;
        x=edges[i][0];
        y=edges[i][1];
        gr[x].push_back(y);
        gr[y].push_back(x);
    }
    dfs(1);

    for(int i=0; i<queries.size();i++){

        int x=queries[i];
        int cnt=0;
        for(int i=1; i<=n;i++){
            if(in[i]>=in[x] and out[i]<=out[x])cnt++;
        }
        res.push_back(cnt);
    }
    return res;
}