#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n; cin>>n;

    if((n & (n-1))==0)  cout<<"Power of 2";
    else cout<<"Not power of 2";

    return 0;
}