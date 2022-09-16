#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define ll long long

ll fibo(ll n){
    if(n==0 || n==1) return n;
    else
    return (fibo(n-1) + fibo(n-2));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll n; cin>>n;
    cout<<fibo(n)<<endl;

    return 0;
}