#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

vector<int>memo;

int fibo(int n){
    if(n<=2)return 1;
    if(memo[n]!=-1) return memo[n];

    return memo[n]=fibo(n-1)+fibo(n-2);
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n ; cin>>n;

    memo.resize(n+1,-1);

    cout<<fibo(n)<<endl;

    
    return 0;
}