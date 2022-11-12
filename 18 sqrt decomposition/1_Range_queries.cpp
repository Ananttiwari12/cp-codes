
// finding sum in a range in O(n^(1/2))

#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n; cin>>n;
    int a[n];
    int m=sqrt(n)+1; 

    int b[m];
    memset(b,0,sizeof(b));

    for(int i=0; i<n;i++){
        cin>>a[i];
        b[i/m] += a[i];
    }

    int query; cin>>query;
    while(query--){

    int l, r;
    cin>>l>>r;
    int ans=0;

    for(int i=l; i<=r;){
        if(i%m==0 and i+m-1<=r){
            // lies completely inside [l...r]
            ans+=b[i/m];
            i+=m;
        }
        else {
            ans += a[i];
            i++;
        }
    }
    cout<<ans<<endl;

    }

    return 0;
}