#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t; cin>>t;
    while(t--){

    int n; cin>>n;
    string s;
    cin>>s;

    if(n%2!=0){
        cout<<-1<<endl;
        continue;
    }

    map<char,int>mp;

    int cnt=0;
    for(int i=0;i<n;i++){
        mp[s[i]]++;
        if(mp[s[i]]>n/2){
            cnt++;
            break;
        }
    }

    if(cnt==1){
        cout<<-1<<endl;
        continue;
    }

    vector<int>v(26,0);
    int total_pair=0;

    for(int i=0;i<n/2;i++){
        if(s[i]!=s[n-i-1])continue;
        else{
            total_pair++;
            v[s[i]-'a']++;
        }
    }

    sort(v.begin(), v.end());

    if(v[v.size()-1]<=(total_pair+1)/2){
        cout<<(total_pair+1)/2<<endl;
    }
    else{
        cout<<v[v.size()-1]<<endl;
    }

    }
    return 0;
}