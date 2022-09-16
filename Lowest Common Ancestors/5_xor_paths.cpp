#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define ll long long

const int N= 1e6;

vector<int>gr[N];

int parent[N]; int dept[N];


void dfs(int cur, int par){
    parent[cur]=par;
    dept[cur]=dept[par]+1;

    for(auto nbr: gr[cur]){
        if(nbr!=par){
            dfs(nbr, cur);
        }
    }
}

int LCA(int u, int v){
    int ans=0;
    if(u==v)return u;

    if(dept[u]<dept[v]) swap(u,v);
    // now u has more depth than v

    int diff= dept[u]-dept[v];
    ans^=u;
    ans^=v;

    while(diff--){
        u=parent[u];
        ans^=u;
    }
    // now u and v has same depth
    while(u!=v){
        u=parent[u];
        v=parent[v];
        ans^=u;
        ans^=v;
    }
    return ans^u;
}

int main(){

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int n; cin>>n;
    for(int i=1; i<n;i++){
        int x,y;
        cin>>x>>y;
        gr[x].push_back(y);
        gr[y].push_back(x);
    }

    dfs(1,0);
    int a,b;
    cin>>a>>b;
    cout<<LCA(a,b)<<endl;
    int aaa=8^6^5^7;
    cout<<aaa;
    
    return 0;
}