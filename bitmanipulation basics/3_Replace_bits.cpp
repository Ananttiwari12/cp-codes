// you are given tow 32 bits number , n and m and tow bit positions i and j>
// Write a method to set all bits between i and j in N equal to M.
// M (becomes a substring of N locationed at and starting at j).

// Example:
// N= 10000000000;
// M=10101;
// i=2, j=6
// Output: 1001010100

#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define ll long long

void clearrangebits(int &n, int i, int j){

int a=(-1)<<j+1;
int b=1<<i - 1;
int mask=a|b;
n=n&mask;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n,i,j,m;
    cin>>n>>i>>j>>m;
    clearrangebits(n,i,j);

    int ans= n | (m<<i);
    cout<<ans;

    return 0;
}