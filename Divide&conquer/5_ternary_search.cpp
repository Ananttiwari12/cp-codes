#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define ll long long

double f(double x){
double y= -(x*x)+4*x;
return y;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    double left=-100;
    double right=100;

    while(right-left>0.000001){
    double mid1=(2 * left + right)/3;
    double mid2=( left + 2 * right)/3;

        if(f(mid1) < f(mid2)){
            left=mid1;
        }
        else{
            right=mid2;
        }
    }

    // cout<<setprecision(10)<<endl;
    cout<<left<<" "<<right<<endl;
    return 0;
}