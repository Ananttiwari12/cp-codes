#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long 

// recursive
// O(k^n);
int countways(int n, int k){
    if(n==0)return 1;
    if(n<0)return 0;
    int ans=0;
    for(int i=1;i<=k;i++){
        ans+=countways(n-i,k);
    }
    return ans;
}
// Top down dp approach
// O(n*k);
int countwaysTD_DP(int n, int k, int *dp){
    if(n==0)return 1;
    if(n<0)return 0;

    if(dp[n]!=0)return dp[n];

    int ans=0;
    for(int i=1;i<=k;i++){
        ans+=countwaysTD_DP(n-i,k,dp);
    }
    return dp[n]=ans;
}


// Bottom up approach
// O(n*k)
int countwaysBU_DP(int n,int k){
    int dp[n];
    dp[0]=1;
    dp[1]=1;
    // cout<<dp[0]<<" "<<dp[1]<<" ";
    for(int i=2;i<=n;i++){
        int ans=0;
        for(int jump=1;jump<=k;jump++){
            if(i-jump>=0)
            ans+=dp[i-jump];
        }
        dp[i]=ans;
        // cout<<dp[i]<<" ";
    }
    return dp[n];
}
// Bottom up approach optimised
// O(n+k)
int countwaysBU_DP_optimised(int n,int k){
    int dp[n];
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=k;i++){
        
        dp[i]=2*dp[i-1]; // this calculation is happening in O(1) time
    }
    for(int i=k+1;i<=n;i++){
        
        dp[i]=2*dp[i-1]-dp[i-(k+1)]; // this calculation is happening in O(1) time
    }
    return dp[n];
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n,k; cin>>n>>k;
    int dp[10000]={0};
    cout<<countways(n,k)<<endl;
    cout<<countwaysTD_DP(n,k,dp)<<endl;
    cout<<countwaysBU_DP(n,k)<<endl;
    // countwaysBU_DP(n,k);
    cout<<countwaysBU_DP_optimised(n,k)<<endl;

    return 0;
}