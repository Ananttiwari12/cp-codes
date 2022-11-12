#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define int long long int

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;cin>>n;
    vector<int>primes={2,3,5,7,11,13,17,19,23,29};
    int m=primes.size();

    int ans=0;

    // making subsets of primes
    for(int i=1;i < (1<<m) ;i++){
    int lcm=1;
        for(int j=0;j<m;j++){

        //if jth of ith element is set then include it
        if((i>>j)&1){
            // cout<<primes[j]<<" ";  ---> for printing subsets
            lcm*=primes[j];
            }
        }
        // cout<<endl;
        if(__builtin_popcount(i)%2==0){
            ans-=(n/lcm);
        }
        else{
            ans+=(n/lcm);
        }
    }

    cout<<ans;

    return 0;
}