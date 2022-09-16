#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long ll;

const ll p=5;

ll add(ll a ,ll b){
    return (a + b) % p; //  (a + b) % p= [(a%p)+(b%p)]%p;
    // return ((a%p)+(b%p))%p;
}
ll sub(ll a,ll b){
    return ((a-b)%p + p)%p;
}
ll multi(ll a,ll b){
    return (a*b)%p;  // (a*b)%p= [(a%p) * (b%p)]%p;
//     return ((a%p) * (b%p))%p;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cout<<add(5,3)<<endl;
    cout<<sub(3,5)<<endl;
    cout<<multi(7,8)<<endl;
    return 0;
}