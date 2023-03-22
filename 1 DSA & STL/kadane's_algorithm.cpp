// maximum subarray sum in O(n)

#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int ans=a[0];
    int sum=0;

    for(int i=0;i<n;i++){
        sum+=a[i];
        ans=max(ans,sum);

        if(sum<=0){
            sum=0;
        }
    }
    cout<<ans<<endl;



    
    return 0;
}