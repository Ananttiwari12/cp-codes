#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define ll long long

ll fact(ll n){
    if(n==0) return 1;
    else return n*fact(n-1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll n; cin>>n;
    cout<<fact(n)<<endl;
    return 0;
}