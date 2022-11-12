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


    int a,b;
    cin>>a>>b;
    ll csum[b+1];
    csum[0]=0;
    for(ll i=1;i<=b;i++){
        if(sieve[i]){
            csum[i]=csum[i-1]+1;
        }
        else{
            csum[i]=csum[i-1];
        }
    }
    cout<<csum[b]-csum[a-1]<<endl;
    
    return 0;
}