#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define ll long long

void dec(ll n){
    if(n==0) return;
    cout<<n<<", ";
    dec(n-1);
}

void inc(ll n){
    if(n==0) return;
    inc(n-1);
    cout<<n<<", ";   // on coming from bottom(base case) to top(bigger no) then that code is writte after the func call
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll n; cin>>n;

    dec(n);
    cout<<endl;
    inc(n);

    return 0;
}