#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

int n,w;
int weight[101];
int value[101];

int dp[101][100001];

int knapsack(int n,int w){
    if(n==0 || w==0) return 0;

    if(dp[n][w]!=-1) return dp[n][w];

    if(weight[n-1]<=w){
        return dp[n][w]=max(value[n-1]+knapsack(n-1,w-weight[n-1]),knapsack(n-1,w));
    }
    else{
        return dp[n][w]=knapsack(n-1,w);
    }
    
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>w;
    for(int i=0;i<n;i++){
        cin>>weight[i]>>value[i];
    }
    
    memset(dp,-1,sizeof(dp));


    cout<<knapsack(n,w)<<endl;

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<w;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }


    
    return 0;
}