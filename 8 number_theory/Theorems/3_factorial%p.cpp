#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define ll long long

const int p=7,N=1e5;
int fact[N];

int mulm(int x,int y){
    return (x*y)%p;
}

void Factorial(){
    fact[0]=1;
    for(int i=1;i<N;i++){
        fact[i]=mulm(fact[i-1],i);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Factorial();

    cout<<fact[5];
    
    return 0;
}