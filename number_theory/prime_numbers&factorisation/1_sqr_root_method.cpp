// program to check prime number by square root method

#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define int long long int
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;cin>>n;
    int count=0;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0){
        count++;
        break;}
    }
    if(count>0) cout<<"Not prime";
    else cout<<"prime";
    return 0;
}