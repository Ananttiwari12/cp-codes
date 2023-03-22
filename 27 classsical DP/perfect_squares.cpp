#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long
#define INF 10000000

int dp[10001];

int numSquares(int n) {
    
    vector<int>v;
    int val=1;
    v.push_back(0);
    while(val*val<=n){
        v.push_back(val*val);
        val++;
        
    }
    int nn=v.size();

    for(int i= 1;i<=n;i++){
        dp[i]=INF;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<nn;j++){
            if(i-v[j]>=0){
                dp[i]=min(dp[i],1+dp[i-v[j]]);
            }   
        }
    }
    if(dp[n]==INF) dp[n]=-1;
    return dp[n];
    
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif


    int n; cin>>n;
    cout<<numSquares(n);
    

    
    
    return 0;
}