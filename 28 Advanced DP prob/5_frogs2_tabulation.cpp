#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

vector<int>dp;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,k; cin>>n>>k;
    int a[n+1];
    for(int i=1;i<=n;i++) cin>>a[i];
    dp.resize(n+1,0);

    dp[1]=0;

    for(int i=2;i<=n;i++){
        int ans=INT_MAX;
        for(int j=1;j<=k;j++){
            if(j<i) {
                ans=min(ans, dp[i-j]+ abs(a[i-j]-a[i]));
            }
        }
        dp[i]=ans;
    }
    cout<<dp[n];


    
    
    return 0;
}