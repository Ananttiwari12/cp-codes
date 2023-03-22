#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

int n,w;
int dp[101][100001];

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>w;
    int weight[n];
    int value[n];

    for(int i=0;i<n;i++){
        cin>>weight[i]>>value[i];
    }
    for(int i=0;i<n+1;i++){
        dp[i][0]=0;
    }
    for(int i=0;i<w+1;i++){
        dp[0][i]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=w;j++){
            if(weight[i-1]<=j){
                dp[i][j]=max(value[i-1]+dp[i-1][j-weight[i-1]],dp[i-1][j]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    cout<<dp[n][w]<<endl;
    
    return 0;
}