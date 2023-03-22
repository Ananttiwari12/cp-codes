#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long



vector<int>gr[100001];
bool visited[100001];
int dp[100001];

int dfs(int src){

	if(dp[src]!=-1)return dp[src];
	int ans=0;
	for(auto node: gr[src]){
		ans=max(ans,1+dfs(node));
	}
	return dp[src]=ans;


}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n,m; cin>>n>>m;

    for(int i=0;i<m;i++){
    	int x,y; cin>>x>>y;
    	gr[x].push_back(y);
    }

    int ans=0;

    memset(dp,-1,sizeof(dp));

    for(int i=1;i<=n;i++){
    	ans=max(ans, dfs(i));
    }

    cout<<ans<<endl;


    
    return 0;
}