#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define ll long long


int tsp(vector<vector<int> >dist, int setofcities, int city, int n){

if(setofcities==(1<<n)-1){
    return dist[city][0];
}
int ans=INT_MIN;
for(int choice=0;choice<n;choice++){
    if((setofcities&(1<<choice))==0){
        int subprob=dist[city][choice]+tsp(dist, setofcities|(1<<choice),choice,n);
        ans=min(ans, subprob);
    }
}
return ans;
        
    }


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);



    int t; cin>>t;
    while(t--){

        int n;
        cin>>n;
        int x[n],y[n];
        for(int i=0;i<n;i++){
            cin>>x[i]>>y[i];
        }
        
        vector<vector<int>> dis;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){

                dis[i][j]= abs(x[i]-x[j])+abs(y[i]-y[j]);
            }
        }

    cout<<tsp(dis,0,1,dis.size());
    }

    return 0;
}