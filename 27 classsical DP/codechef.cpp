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
    	string s; cin>>s;

    	int o=0;
    	vector<int>v;
    	for(int i=0;i<n;i++){
    		if(s[i]=='1'){
    			v.push_back(i+1);
    			o++;
    		}
    	}

    	if(s=="1")cout<<"NO"<<endl;
    	else if(s=="10")cout<<"NO"<<endl;
    	else if(o<=3) cout<<"YES"<<endl;
    	else cout<<"NO"<<endl;
    	
    }
    
    
    return 0;
}