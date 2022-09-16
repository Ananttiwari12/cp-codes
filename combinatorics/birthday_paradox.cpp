#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    float p;cin>>p;
    
    int people=1;int num=365; int deno=365;
    float prob=1;
    while(1){
        prob=prob/deno*num;
        // prob/=deno;

        if(prob<p) break;

        num--;
        people++;
    }
    cout<<"no of peoples are "<<people;

    return 0;
}