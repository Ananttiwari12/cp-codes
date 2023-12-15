#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define int long long

#define mod 1000000007

void dfs_cycle(int u, int p, int color[], int par[], int& cyclenumber, vector<int>gr[], vector<vector<int>>&cycles){
    if (color[u] == 2){
        return;
    }
    if (color[u] == 1) {
        vector<int> v;
        cyclenumber++;      
        int cur = p;
        v.push_back(cur);
        while (cur != u) {
            cur = par[cur];
              v.push_back(cur);
        }
        cycles.push_back(v);
        return;
    }
    par[u] = p;
    color[u] = 1;

    for (int v : gr[u]) {
        if (v == par[u]) {
            continue;
        }
        dfs_cycle(v, u, color, par, cyclenumber,gr,cycles);
    }
    color[u] = 2;
}



int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t; cin>>t;
    while(t--){

    	int n,a,b; cin>>n;
    	vector<int>gr[n+1];

    	for(int i=0;i<n;i++){
    		int x,y; cin>>x>>y;
    		gr[x].push_back(y);
    		gr[y].push_back(x);
    	}

    	vector<vector<int>>cycles;
    	int color[n+1];
    	memset(color,0,sizeof(color));
    	int cyclenumber=0;
    	int par[n+1];

    	dfs_cycle(1,0,color,par,cyclenumber,gr,cycles);


    	int cnt=0;
    	for(int i=0;i<cyclenumber;i++){

    		int mn=INT_MAX;
    		int node=-1;
    		for(auto x: cycles[i]){
    			cout<<x<<" ";
    		}

            cout<<endl;
        }



    }
    return 0;
}