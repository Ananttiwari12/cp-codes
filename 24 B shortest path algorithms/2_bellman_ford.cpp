#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

vector<int>bellman_ford(vector<vector<int>>edges, int src, int n){

	vector<int>dist(n+1,INT_MAX);
	dist[src]=0;

	for(int i=0;i<n-1;i++){
		for(auto edge: edges){
			int u=edge[0];
			int v=edge[1];
			int wt=edge[2];

			if(dist[u]!=INT_MAX and dist[v]>dist[u]+wt){
				dist[v]=dist[u]+wt;
			}
		}
	}
	
	// negative cycle detection
	for(auto edge: edges){
		int u=edge[0];
		int v=edge[1];
		int wt=edge[2];

		if(dist[u]!=INT_MAX and dist[v]>dist[u]+wt){
			dist[v]=dist[u]+wt;
			cout<<"Negative cycle found";
			exit(0);
		}
	}
	return dist;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // #endif

    int n,m;
    cin>>n>>m;

    vector<vector<int>>edges;

    for(int i=0;i<m;i++){
    	int x,y,w;
    	cin>>x>>y>>w;
    	edges.push_back({x,y,w});
    }

    vector<int>distances=bellman_ford(edges,1,n);

    for(int i=1;i<=n;i++){
    	cout<<"Node "<<i<<" is at dist--> "<<distances[i]<<endl;
    }

    return 0;
}