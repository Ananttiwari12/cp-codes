#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define ll long long

// recusive approach: time complexity-exponential

int countBST(int n){
    if(n==0 || n==1) return 1;
    int ans=0;
    for(int i=1;i<=n;i++){
        int x=countBST(i-1);
        int y=countBST(n-i);
        ans+=x*y;
    }
    return ans;
}


// O(n^2) : dp memoization

int countBSTtopdown(int n,int dp[]){
    if(n==0 || n==1){
        return 1;
    }
    if(dp[n]!=0) return dp[n];

    int ans=0;
    for(int i=1;i<=n;i++){
        int x=countBSTtopdown(i-1,dp);
        int y=countBSTtopdown(n-i,dp);
        ans+=x*y;
    }
    return ans;
}

int countBSTbottomup(int N){
    vector<int> dp(N+1,0);
    
    dp[0]=dp[1]=1;
    if(dp[N]!=0) return dp[N];

    int ans=0;
    for(int n=2;n<=N;n++){
        for(int i=1;i<=n;i++){
            dp[n]+=dp[i-1]*dp[n-i];
        }
    }
    return dp[N];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n; cin>>n;

    int dp[100]={0};
    
    cout<<countBST(n)<<endl;
    cout<<countBSTtopdown(n,dp)<<endl;
    cout<<countBSTbottomup(n)<<endl;
    return 0;
}