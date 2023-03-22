#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

vector<string>ans;
set<string>se;
void generate(string &s, int l, int r){

	if(l==r){
		if(!se.count(s))
		{
		ans.push_back(s);
		se.insert(s);
	}
}
	else{
	for(int i=l;i<=r;i++){
		swap(s[l], s[i]);
		generate(s,l+1,r);
		swap(s[l],s[i]);
	}
}
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    string s; cin>>s;

    int n=s.length();

    generate(s,0,n-1);
    cout<<ans.size()<<endl;
    sort(ans.begin(), ans.end());
    for(int i=0;i<ans.size();i++){
    	cout<<ans[i]<<endl;
    }

    

    
    
    return 0;
}