#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

int dp[101][1001];

int solve(int w[], int v[], int n, int idx, int wt, int cur, int choosen){

	if(idx==n){
		if(choosen==1){
			return v[idx-1];
		}
	else return 0;
	}

	// if(cur>wt){
	// 	return 0;
	// }

	if(dp[idx][choosen]!=-1)return dp[idx][choosen];
	int ans=0;

	if(choosen==1 and idx!=0){
		ans+=v[idx-1];
	}
	if(cur+w[idx]<=wt){
		ans+=max(solve(w,v,n,idx+1,wt,cur,0),solve(w,v,n,idx+1,wt,cur+w[idx],1));

	}
	else{
		ans+=solve(w,v,n,idx+1,wt,cur,0);
	}
	return dp[idx][choosen]=ans;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n,wt; cin>>n>>wt;

    int w[n],v[n];

    for(int i=0;i<n;i++){
    	cin>>w[i]>>v[i];
    }

    memset(dp,-1,sizeof(dp));
    int ans1=solve(w,v,n,0,wt,0,0);
    memset(dp,-1,sizeof(dp));
    int ans2=solve(w,v,n,0,wt,0,1);

    cout<<max(ans1,ans2);

    return 0;
}