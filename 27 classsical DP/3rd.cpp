#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long
const int mx=200001;
int f[200002];
int iif[200002];

int multiply(int a, int b){
	int ans= ((a%mod)*(b%mod))%mod;
	return ans%mod;

}
int pwr (int a, int b){
    int res=1;
    while(b){
        if(b&1){
        	res=((res%mod)*(a%mod))%mod;
        	res%=mod;
        }
        a=((a%mod)*(a%mod))%mod;
        b>>=1;
    }
    return res%mod;
}

int mi(int a, int m=mod){
	int ans=pwr(a,m-2);
	return ans;
}
void generate(){
	f[0]=1;
	iif[0]=1;
	for(int i=1;i<=200001;i++){
		f[i]=multiply(f[i-1],i);
		iif[i]=multiply(iif[i-1],mi(i));
	}
}



int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
	generate();
    int t; cin>>t;
    while(t--){

    	int n; cin>>n;
    	string s1;
    	string s2;

    	cin>>s1>>s2;
    	int same_pos=0;
    	for(int i=0;i<n;i++){
    		if(s1[i]==s2[i]){
    			same_pos++;
    		}
    	}
    	int len=n;
    	len-=same_pos;
    	if((len&(len-1))!=0){
    		cout<<0<<endl;
    	}
    	else{
    		
    	int ans=pwr(2,same_pos);
		int ans1=multiply(iif[len / 2], iif[len / 2]);
		int ans2=multiply(f[len], ans1 );
		ans = multiply(ans,ans2);

		cout << ans%mod << endl;
	}
    	}    
    return 0;
}