// multiplicative modulo inverse

// given a and m, find mmi x of a under modulo m.
// The MMI is an integer 'x' such that.
// {ax is congruent to 1(mod m) }  or  (a*x)%m=1
//  1<=x<=m-1  and MMI exist only when a and m are co-prime that is gcd(a,m)=1


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
    int MMI(int a,int m){
        vector<int>multimodin=extendedgcd(a,m);
        int x=multimodin[0];
        int gcd=multimodin[2];
        if(gcd==1){
        int ans=(x%m+m)%m; // x can be negative also so to get ans in positive range we are doing this step
        return ans;
        }
        else{
        return -1;
        cout<<"MMI does not exist";
        }
    }
    

    int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a,m;
    cin>>a>>m;
    cout<<MMI(a,m);
    
    return 0;
}