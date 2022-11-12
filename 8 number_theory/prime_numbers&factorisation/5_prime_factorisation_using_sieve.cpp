#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define N 1000000
#define ll long long

int countPrimes(int n){
    vector<int>sieve(N,1);

    sieve[1]=sieve[0]=0;

    // start from 2 and mark all multiples of ith number(prime) as not prime
    for(ll i=2;i<=N;i++){
        if(sieve[i]){
            for(ll j=i*i;j<=N;j=j+i){
                sieve[j]=0;
            }
        }
    }
    int cnt=0;
    for(ll i=0;i<n;i++){
        if(sieve[i]){
            cnt++;
        }
    }
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int>sieve(N,1); // initialising vector of size N with all elements 1
    int n;cin>>n;

    cout<<countPrimes(n);
    return 0;
}