#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define ll long long

bool isSorted(ll arr[], ll n){
    if(n==1) return true;
    if( arr[0]<arr[1] && isSorted(arr+1,n-1)) return true;
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll n; cin>>n;
    ll a[n];
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }

    cout<<isSorted(a,n)<<endl;
    return 0;
}