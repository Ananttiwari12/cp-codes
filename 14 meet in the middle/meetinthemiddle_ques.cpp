#include<bits/stdc++.h>
using namespace std;
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

long long solve(int n,int x, vector<int> a){
    vector<ll>left,right;

    for(ll i=0;i<n;i++){
        if(i<=n/2){
            left.push_back(a[i]);
        }
        else{
            right.push_back(a[i]);
        }
    }

    vector<ll>leftsums=subsetsum(left);
    vector<ll>rightsums=subsetsum(right);

    sort(rightsums.begin(),rightsums.end());
    ll ans=0;
    for(auto k: leftsums){
        for(auto y: rightsums){
            if(k+y==x) ans++;
        }
    }
    return ans;
}