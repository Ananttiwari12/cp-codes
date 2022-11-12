#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define ll long long

vector<vector<int> >binomial_coef(int n, int k){

    vector<vector<int> >table(n+1,vector<int>(k+1,0));
    for(int i=0;i<=n;i++){
        for(int j=0;j<=min(i,k);j++){
            //base case
            if(j==0 || j==i){
                table[i][j]=1;
            }
            //filling the table
            else{
            table[i][j]=table[i-1][j-1]+table[i-1][j];
            }
        }
    }
    return table;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;
    vector<vector<int> > table=binomial_coef(n,n);
    int queries; cin>>queries;
    while(queries--){
        int k;
        cin>>k;
        if(k<=n) cout<<table[n][k]<<endl;
    }

    return 0;
}