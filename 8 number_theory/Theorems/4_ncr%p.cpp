#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define ll long long

const ll p=1e9+7,N=1e5;
ll fact[N];

ll mulm(ll x,ll y){
    return (x*y)%p;
}

ll powm(ll x,ll y){
    ll res=1;
    while(y){
        if(y&1) res=mulm(res,x);
        y/=2;
        x=mulm(x,x);
    }
    return res;
}

void Factorial(){
    fact[0]=1;
    for(ll i=1;i<N;i++){
        fact[i]=mulm(fact[i-1],i);
    }
}

ll inverse(ll x){
    return powm(x,p-2);
}

ll ncr(ll n,ll r){
    return mulm(mulm(fact[n],inverse(fact[r])),inverse(fact[n-r]));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Factorial();

    cout<<fact[5]<<endl;
    cout<<ncr(5778,123);
    
    return 0;
}