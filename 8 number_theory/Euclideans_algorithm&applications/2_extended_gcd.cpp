#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

vector<int>extendedgcd(int a,int b){
    {if(b==0)
    // return the values of x and y
    return {1,0,a};
    }

    vector<int>result=extendedgcd(b,a%b);

    // After recursive call is over
    int x1=result[0];
    int y1=result[1];
    int gcd=result[2];

    int x=y1;
    int y=x1-(a/b)*y1;

    return {x,y,gcd};
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int a,b;
    cin>>a>>b;

    // ax+by=gcd(a,b);
    int x,y;

    vector<int>result= extendedgcd(a,b);
    cout<<result[0]<< " and "<<result[1]<< "and gcd is "<<result[2]<<endl;

    return 0;
}