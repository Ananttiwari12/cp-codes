#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t; cin>>t;
    while(t--){

        int w,h,n;
        cin>>w>>h>>n;

        if(n==0){
            cout<<w*h<<endl;
        }
        else{
        vector<int>x(n+2),y(n+2);
        x[0]=0;
        y[0]=0;

        for(int i=1;i<=n;i++){
           cin>>x[i]>>y[i];
        }
        x[n+1]=w;
        y[n+1]=h;


        sort(x.begin(),x.end());
        sort(y.begin(),y.end());

        vector<int> xx(n+1),yy(n+1);

        for(int i=0;i<n;i++){
            xx[i]= x[i+1]-x[i]-1;
            yy[i]= y[i+1]-y[i]-1;

        }
        xx[n]=x[n+1]-x[n];
        yy[n]=y[n+1]-y[n];
       

        sort(xx.begin(),xx.end());
        sort(yy.begin(),yy.end());

        cout<<xx[xx.size()-1]*yy[yy.size()-1]<<endl;
        }

    }
    return 0;
}