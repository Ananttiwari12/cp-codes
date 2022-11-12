// FERMAT's THEOREM

// a^(p) ≅ a (mod p)
//  by using this::   (x/y)%p = ( (x%p) * ( y^(p-2)%p ) )%p;

const int p=5;

int mulm(int x,int y){
    return (x*y)%p;
}

int powm(int x,int y){
    int res=1;
    while(y){
        if(y&1) res=res*x;
        y/=2;
        x=mulm(x,x);
    }
    return res;
}

int divm(int x,int y){
    return mulm(x,powm(y,p-2));
}

#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000009
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cout<<divm(28,2);
    return 0;
}