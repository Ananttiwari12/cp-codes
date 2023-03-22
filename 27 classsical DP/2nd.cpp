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

    	int ans=0;

    	if(s[0]=='0'){

    		int cnt=0;
    		int len=0;

    		for(int i=0;i<n;i++){
    			if(s[i]=='1'){
    				cnt++;
    			}
    			else{
    				len=max(len,cnt);
    				cnt=0;
    			}
    		}
    		len=max(len,cnt);
    		cout<<len<<endl;
    	}

    	else{

    		int initone=0;
    		int idx=0;
    		int len=0;
    		for(int j=0;j<n;j++){
    			if(s[j]=='1'){
    				initone++;
    			}
    			else{
    				
    				idx=j;
    				break;
    			}
    		}

    		
    		int cnt=0;
            if(idx!=0){
    		for(int i=idx;i<n;i++){
    			if(i<n and s[i]=='1'){
    				cnt++;
    			}
    			else{
    				len=max(len,cnt);
    				cnt=0;
    			}
    		}
    		len=max(len,cnt);
        }
    		ans=max(ans,len+initone);
    		cout<<ans<<endl;
    	} 
    }

    
    
    return 0;
}
