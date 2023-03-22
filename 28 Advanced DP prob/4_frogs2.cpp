#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

int n,k;
vector<int>v;
vector<int>memo;

int frogs(int i){
    int ans=INT_MAX;
    if(i==1) return 0;
    if(i>1 and i<=k)return abs(v[i]-v[1]);
    if(i<0)return INT_MAX;
    if(memo[i]!=-1) return memo[i];
    for(int j=1;j<=k;j++){
        ans=min(ans,frogs(i-j)+abs(v[i]-v[i-j]));
    }
    return memo[i]=ans;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>k;
    v.resize(n+1);
    memo.resize(n+1,-1);

    for(int i=1;i<=n;i++) cin>>v[i];

    cout<<frogs(n);
    
    return 0;
}