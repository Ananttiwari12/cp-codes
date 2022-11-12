#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

const int N=100000;
int a[N][3];
int dp[N][3];
int memo[N][3];

int vacation(int i, int j){
    int ans=INT_MIN;
    if(i==0 and j==0) return a[0][0];
    if(i==0 and j==1) return a[0][1];
    if(i==0 and j==2) return a[0][2];
    
    if(memo[i][j]!=-1) return memo[i][j];

    for(int jj=0;jj<3;jj++){ // 1 2
        if(jj!=j){
            ans=max(ans,vacation(i-1,jj)+a[i][j]);
        }
    }
    return memo[i][j]=ans;
}
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
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            memo[i][j]=-1;
        }
    }
    memo[0][0]=a[0][0];
    memo[0][1]=a[0][1];
    memo[0][2]=a[0][2];

    int res=INT_MIN;
    for(int k=0;k<3;k++){
        res=max(res,vacation(n-1,k));
    }
    cout<<res<<endl;
    return 0;
}