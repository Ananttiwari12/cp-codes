#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

int minjumps(vector<int>arr,int n, vector<int>dp,int i){
    if(i==n-1)return 0;
    if(i>=n)return INT_MAX;
    if(dp[i]!=0)return dp[i];

    int steps=INT_MAX;

    int max_jump=arr[i];
    
    for(int jump=1; jump<=max_jump; jump++){
        int nextcell= i+jump;
        int subprob=minjumps(arr,n,dp,nextcell);
        if(subprob!=INT_MAX){
            steps=min(steps,subprob+1);
        }
    }
    return dp[i]=steps;

}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int>arr{3,4,2,1,2,3,7,1,1,3};
    int n=arr.size();
    vector<int>dp(n,0);
    cout<<minjumps(arr,n,dp,0);
    
    return 0;
}