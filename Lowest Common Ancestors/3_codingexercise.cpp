#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define ll long long

const int N= 1e6,M=20;

vector<int>gr[N];

int parent[N][M];
int dept[N];


void dfs(int cur, int par){
    dept[cur]=dept[par]+1;

    // creating sparse table
    parent[cur][0]=par;
    for(int j=1; j<M;j++){
        parent[cur][j]=parent[parent[cur][j-1]][j-1];
    }

    for(auto nbr: gr[cur]){
        if(nbr!=par){
            dfs(nbr, cur);
        }
    }
}

int LCA(int u, int v){
    if(dept[u]<dept[v]) swap(u,v); // now u and v are equal
    int diff= dept[u]-dept[v];

    // making u and v on the same level
    for(int j=M-1;j>=0;j--){
            if((diff>>j)&1)
            u=parent[u][j];
        }

    if(u==v)return u;
    for(int j=M-1;j>=0;j--){
        if(parent[u][j]!=parent[v][j]){
            u=parent[u][j];
            v=parent[v][j];
        }
    }
    return parent[u][0];
    //return parent[v][0];
}

vector<int> LCA(int n, vector<vector<int>>edges, vector<vector<int>>queries)
{
    vector<int>result;
    for(int i=0; i<n-1;i++){
        int x=edges[i][0];
        int y=edges[i][1];
        gr[x].push_back(y);
        gr[y].push_back(x);
    }
    dfs(1,0);
    for(int i=0; i<queries.size();i++){
        result.push_back(LCA(queries[i][0],queries[i][1]));
    }
    return result;
}
int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    vector<vector<int>>edges={{1,2},{1,3},{3,4},{3,5}};
    vector<vector<int>>queries={{2,3},{3,5},{1,4}};
    vector<int>ans=LCA(n,edges,queries);
   
    for(int i=0; i<ans.size();i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}
