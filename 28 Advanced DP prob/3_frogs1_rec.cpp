#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

vector<int>memo;
vector<int>v;
int n;

int frogs(int i){
    if(i==0) return 0;
    if(i==1) return abs(v[1]-v[0]);

    if(memo[i]!=-1) return memo[i];

    return memo[i]= min(frogs(i-1)+abs(v[i]-v[i-1]),frogs(i-2)+abs(v[i]-v[i-2]));
    
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;
    memo.resize(n+1,-1);
    v.resize(n+1);
    for(int i=0;i<n;i++) cin>>v[i];

    cout<<frogs(n-1);



    
    return 0;
}