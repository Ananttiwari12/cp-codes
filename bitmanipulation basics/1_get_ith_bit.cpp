#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define ll long long

int get_ith_bit(int n, int i){
    int mask=1<<i;
    return (n & mask)>0 ? 1:0;
}

void clearithbit(int &n, int i){
    int mask= ~(1 << i);
    n= n & mask; 
}

void setIthbit(int &n, int i){
    int mask= 1<<i;
    n=n|mask;
}

void updatebit(int &n, int i, int v){
    clearithbit(n,i);
    int mask= v<<i;
    n=n | mask;
}

void clearibits(int &n, int i){
    int mask=(-1<<i);
    n=n & mask;
}

void clearRangeofbits(int &n, int i, int j){
    int a= (-1<<j+1); 
    int b= (1<<i) -1;
    int mask= a|b;
    n= n & mask;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n,i; cin>>n>>i;
    
    // clearithbit(n,i);
    // cout<<get_ith_bit(n,i);

    // setIthbit(n,i);
    // cout<<n;

    // updatebit(n,i,0);
    
    // clearibits(n,i);

    int j;cin>>j;
    clearRangeofbits(n,i,j);
    cout<<n<<endl;
    
    return 0;
}