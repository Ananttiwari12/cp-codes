#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

    vector<int>dp(100001,1);
int LIS(vector<int>arr,int n){
    
    int len=1;
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[j]<arr[i]){
                dp[i]=max(dp[i],1+dp[j]);
                len=max(len,dp[i]);
            }
        }
    }
    return len;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int>arr;

    int n; cin>>n;
    for(int i=0;i<n;i++){
        int x; cin>>x;
        arr.push_back(x);
    }
    cout<<LIS(arr,n)<<endl;
    
    return 0;
}
