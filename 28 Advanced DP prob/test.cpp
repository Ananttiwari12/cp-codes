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
    int a[n];
    vector<int>pos;
    vector<int>neg;
    for(int i=0;i<n;i++){
    	cin>>a[i];
    	if(a[i]>=0) pos.push_back(a[i]);
    	else neg.push_back(a[i]);
    }

    if(!pos.empty()){
    	sort(pos.begin(), pos.end());
    }
    if(!neg.empty()){
    	sort(neg.begin(), neg.end(), greater<int>());
    }

    if(!pos.empty()){
    	if(pos[0]==0){
    		cout<<-1<<endl;
    	}
    	else{
    		int ans1=pos[0]-1;
    		if(!neg.empty()){
    			int ans2=neg[0]+1;
    		

    		while(ans2>-1*ans1){
    			ans1--;
    		}
    		if(ans1<0){
    			cout<<-1<<endl;
    		}
    		else{
    			cout<<ans1<<endl;
    		}
    	}
    	else{
    		cout<<ans1<<endl;
    	}



    	}
    }
    else{
    	cout<<abs(neg[0]+1)<<endl;
    }





    }
    
    return 0;
}