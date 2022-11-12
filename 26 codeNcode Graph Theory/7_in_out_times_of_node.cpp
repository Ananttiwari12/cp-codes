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


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    return 0;
}