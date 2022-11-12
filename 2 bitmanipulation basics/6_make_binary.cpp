#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define ll long long

int convert_to_binary(int n){

    int ans=0;
    int power_of_10=1;

    while(n>0){

    ans= ans + (n&1)*power_of_10;
    power_of_10 *= 10;
    n=n>>1;                                         
    }
    
    return ans;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin>>n;
    cout<<convert_to_binary(n);
    
    return 0;
}