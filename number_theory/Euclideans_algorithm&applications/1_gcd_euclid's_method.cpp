#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int gcd(int a,int b){
    if(b==0)
    return a;
    return gcd(b,a%b);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a,b;cin>>a>>b;
    cout<<gcd(a,b); 
    
    return 0;
}