#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define ll long long

int count_set_bits(int n){
    int count=0;
    while(n>0){
        int last_bit= (n&1);
        count+=last_bit;
        n=n>>1;
    }
    return count;
}


// count set bits hack: faster method

int cnt_setbits(int n){
    int ans=0;
    while(n>0){
        n=(n&(n-1));
        ans++;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n; cin>>n;

    cout<<count_set_bits(n)<<endl;
    cout<<cnt_setbits(n);
    return 0;
}