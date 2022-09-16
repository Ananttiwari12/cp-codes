#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define N 1000000
#define ll long long

void primesieve(vector<int>&sieve){

    //mark 1 and 0 as not prime
    sieve[1]=sieve[0]=0;

    // start from 2 and mark all multiples of ith number(prime) as not prime
    for(ll i=2;i<=N;i++){
        if(sieve[i]){
            for(ll j=i*i;j<=N;j=j+i){
                sieve[j]=0;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int>sieve(N,1); // initialising vector of size N with all elements 1
    primesieve(sieve);

    for(ll i=1033;i<=8179;i++){
        if(sieve[i]){
            cout<<i<<" ";
        }
    }
    
    return 0;
}