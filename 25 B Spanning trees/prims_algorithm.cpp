#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

class graph{
	int V;
	vector<pair<int,int>>*gr;
	int *Tree;
public:
	graph(int n){
		V=n+1;
		gr=new vector<pair<int,int>>[n+1];
		Tree= new int[V];
	}

	void addEdge(int x, int y, int w){
		gr[x].push_back({y,w});
		gr[y].push_back({x,w});
	}

	int prims(){

		bool *visited= new bool[V]{0};
		int ans=0;
		priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>>pq;
		pq.push({0,1}); // weight  node // This is a strategic push

		while(!pq.empty()){
			pair<int,int>p = pq.top();
			pq.pop();

			int next_node=p.second;
			int weight=p.first;

			if(visited[next_node]==1){
				continue;
			}

			ans+=weight;
			visited[next_node]=1;
			
			for(auto x: gr[next_node]){
				if(visited[x.first]==0){
					pq.push({x.second,x.first});
					Tree[x.first]=next_node;
				}
			}
		}
		return ans;
	}
};

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n,m; cin>>n>>m;
	graph gr(n);

	for(int i=0;i<m;i++){
		int x,y,w; cin>>x>>y>>w;
		gr.addEdge(x,y,w);
	}

	cout<<gr.prims();

	return 0;
}