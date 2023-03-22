// Give a 4xn board and tiles of size 4x1, count the number if ways to tile the given
// board using the 4x1 tiles.
// A tile can either be placed horizontally i.e., as a 1x4 tile or vertically i.e.,
// as 4x1 tile.
// input- n; output: no of ways.

#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define ll long long

ll tilling_prob(ll n){
    if(n==0 || n==1 || n==2 || n==3) return 1;
    if(n==4) return 2;
    return tilling_prob(n-1) + tilling_prob(n-4);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n; cin>>n;
    cout<<tilling_prob(n)<<endl;

    return 0;
}