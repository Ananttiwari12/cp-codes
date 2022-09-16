#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define ll long long

//brute force
void primefactorise(ll n){
    for(ll i=2;i<n;i++){
        ll count=0;
        if(n%i==0){
            while(n%i==0){
                count++;
                n/=i;
            }
             cout<<i<<"^"<<count<<" ";
        }
    }
    if(n!=1){
        cout<<n<<"^"<<1;
    }
}

//optimised approach
// If a number doesn't have any factor till sqrt(n)
// then it is a prime number.

void factor(ll n){
    for(ll i=2;i*i<=n;i++){
        ll count=0;
        if(n%i==0){
            while(n%i==0){
                count++;
                n/=i;
            }
             cout<<i<<"^"<<count<<" ";
        }
    }
    //out of loop
    if(n!=1){
        cout<<n<<"^"<<1;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll n;cin>>n;
    // primefactorise(n);
    factor(n);
    return 0;
}