#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define ll long long

ll pow(ll a, ll n){
    if(n==0) return 1;
    return a * pow(a,n-1);
}

ll fastpow(ll a, ll n){
    if(n==0) return 1;
    ll subpow=fastpow(a,n/2);
    ll subpowsq=subpow*subpow;
    if(n&1) return a*subpowsq;
    return subpowsq;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll a,b;
    cin>>a>>b;
    cout<<pow(a,b)<<endl;
    cout<<fastpow(a,b);
    return 0;
}