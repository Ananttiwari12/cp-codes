#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define ll long long

vector<ll> subsetsum (vector<ll>a){

vector<ll> result;
int n=a.size();

for(ll i=0;i<(1<<n);i++){
    ll sum=0;
    for(ll j=0;j<n;j++){
        if((i>>j)&1){
            sum+=a[j];
        }
    }
        result.push_back(sum);
}
return result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll n, a, b;
    cin>>n>>a>>b;

    vector<ll> v(n);
    vector<ll>left,right;

    for(ll i=0;i<n;i++){
        cin>>v[i];
    }

    for(ll i=0;i<n;i++){
        if(i<=n/2){
            left.push_back(v[i]);
        }
        else{
            right.push_back(v[i]);
        }
    }

    vector<ll>leftsums=subsetsum(left);
    vector<ll>rightsums=subsetsum(right);

    sort(rightsums.begin(),rightsums.end());

    ll ans=0;
    for(auto x:leftsums){
        ans+=upper_bound(rightsums.begin(),rightsums.end(),b-x)-lower_bound(rightsums.begin(),rightsums.end(),a-x);
    }
    cout<<ans<<endl;
    return 0;
}