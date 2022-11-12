//count the number of binary strings with no consecutive ones that acn be formed using a 
//binary string of length n
// input: n, output: no of ways

#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define ll long long

ll cnt_binstr(ll n){
    if(n==0) return 1;
    if(n==1) return 1;
    if(n==2) return 2;
   

    return cnt_binstr(n-1) + cnt_binstr(n-2);

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll n; cin>>n;
    cout<<cnt_binstr(n);

    return 0;
}