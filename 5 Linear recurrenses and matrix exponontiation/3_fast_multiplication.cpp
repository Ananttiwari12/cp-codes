#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

int multiply(int a, int b, int c){
    int res=0;
    while(b){
        if(b&1)res=res+a,res %=c;
        a+=a;; a%=c;
        b/=2;
    }
    return res;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cout<<multiply(2,4,1e9+7);
    return 0;
}