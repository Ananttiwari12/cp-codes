
#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long



int dp[1001][101];
int solve(vector<int>&prices, int n , int state, int idx,int k, int cnt){
if(cnt==2*k){
    if(idx<n and state==1)return prices[idx];
    else return 0;
}
if(idx==n-1){
    if(state==1)return prices[idx];
    else return 0;
}
if(dp[idx][cnt]!=-1)return dp[idx][cnt];
int ans=0;
int ans1=0;
int ans2=0;
// state =1: buy and if state=0 sell
ans=solve(prices,n,state,idx+1,k,cnt);
if(state==0){
    ans1=-prices[idx]+solve(prices,n,state^1,idx+1,k,cnt+1);
}
if(state==1){
    ans2=prices[idx]+solve(prices,n,state^1,idx+1,k,cnt+1);
}

return dp[idx][cnt]=max(ans,ans2+ans1);
}

int maxProfit(int k, vector<int> prices) {
    int n=prices.size();
        memset(dp,-1,sizeof(dp));
        return solve(prices,n,0,0,k,0);
}



int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n,k; cin>>n>>k;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    cout<<maxProfit(k,v);

    
    
    return 0;
}