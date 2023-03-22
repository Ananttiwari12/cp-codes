#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

int n,W;
int values[100];
int w[100]; int memo[100][100001];

int knapsack(int idx, int weight){
    if(idx>=n)return 0;

    int &ans=memo[idx][weight];
    if(ans!=-1) return ans;

    // do not take weight
    ans=knapsack(idx+1, weight);

    // take weight
    if(weight+w[idx]<=W){
        ans=max(ans,values[idx]+knapsack(idx+1,weight+w[idx]));
    }
    return ans;
}


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>W;

    for(int i=0;i<n;i++){
        cin>>w[i]>>values[i];
    }

    memset(memo,-1,sizeof(memo));

    cout<<knapsack(0,0);
    
    return 0;
}