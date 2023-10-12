#include<bits/stdc++.h>
#define endl "\n"
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    vector<int>v(n);
    v[0]=1;
    for(int i=1;i<n-1;i++){ 
        if(n%(i+1)==0){
            v[i]=i+1;
        }
    }
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    return 0;
}