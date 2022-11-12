#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

int solve(int n) {
    
    int cnt=0;
    vector<int>res;
    while(n){
        if(n&1==1){
            res.push_back(1);
            n=n>>1;
        }
        else{
            res.push_back(0);
            n=n>>1;
        }
    }
    
    int b=res.size();
    int ans=0;
    for(int i=0;i<b;i++){
        if(res[i]==1){
            cnt++;
        }
        else{
            ans=max(ans,cnt);
            cnt=0;
        }
    }
    reverse(res.begin(),res.end());

    cnt=0;
    for(int i=0;i<b;i++){
        if(res[i]==1){
            cnt++;
        }
        else{
            ans=max(ans,cnt);
            cnt=0;
        }
    }
    return ans;
     
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin>>n;

    int cnt=0;
    vector<int>res;  
    cout<<solve(n);
    return 0;
}