#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define ll long long

ll gcd(ll a, ll b){
    if(b==0) return a;
    return gcd(b,a%b);
}
ll eulers_totient(ll n){
    ll ans=0;
        
    for(ll i=1;i<n;i++){
        if(gcd(n,i)==1){
            ans++;
        }
    }   
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll n;cin>>n;
    cout<<eulers_totient(n);

    return 0;
}