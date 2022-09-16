#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define ll long long

ll fastpow(ll a, ll n){
    if(n==0) return 1;
    ll subpow=fastpow(a,n/2);
    ll subpowsq=subpow*subpow;
    if(n&1) return a*subpowsq;
    return subpowsq;
}

bool isPowerOfFour(int n) {
    
        int cnt=0;
        int idx=0;

        while(n!=0){
            if(n&1==1){
                cnt++;
            }
                idx++;
            n=n>>1;
        }
        
        if(n%2==0){
            if(cnt==1 and (idx-1)%4==0){
                return true;
            }
            else return false;
        }
        else if(n==1) return true;
        else{
           
          return false;
    }
}