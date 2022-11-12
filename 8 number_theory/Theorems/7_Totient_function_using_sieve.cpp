#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define ll long long
#define N 1000

void Totient_func(){
    vector<int>primes(N,1);
    vector<ll>tot(N);
    primes[0]=primes[1]=0;
    for(ll i=2;i<N;i++){
        for(ll j=i*i;j<N;j+=i){
            primes[j]=0;
        }
    }

    iota(tot.begin(),tot.end(),0); // will fill all indexes of tot with itself
    for(ll i=2;i<N;i++){
        if(primes[i]==1){
            //multipkes of prime
            for(ll j=i;j<N;j+=i){
                tot[j]/=i;
                tot[j]*=(i-1);
            }
        }
    }
    for(ll i=1;i<N;i++){
        cout<<i<<" "<<tot[i]<<endl;
    }
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Totient_func();
    
    return 0;
}