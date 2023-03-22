#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

const int N=100000;
int a[N][3];
int dp[N][3];

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            cin>>a[i][j];
        }
    }
    dp[0][0]=a[0][0];
    dp[0][1]=a[0][1];
    dp[0][2]=a[0][2];

    for(int i=1;i<n;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                if(k!=j){
                    dp[i][j]=max(dp[i][j],dp[i-1][k]+a[i][j]);
                }
            }
        }
    }

    int ans=INT_MIN;
    for(int i=0;i<3;i++){
        ans=max(ans,dp[n-1][i]);
    }
    cout<<ans<<endl;
 
    return 0;
}