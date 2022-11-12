// Given n friends who want to go to party, each one can remain single 
// or can be paired up with some other friend. Each friend can be paired only once.
// Find out the total number of ways in which friends can remain single or can be 
// paired up.

#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define ll long long

ll frndpair(ll n){
    if(n==0 || n==1) return 1;
    if(n==2) return 2;
    return frndpair(n-1)+(n-1)*frndpair(n-2);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n; cin>>n;
    cout<<frndpair(n);

    return 0;
}