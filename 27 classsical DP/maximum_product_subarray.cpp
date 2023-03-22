#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007

int maxProduct(vector<int> nums){
    int n=nums.size();

    int dp[n];

    dp[0]=nums[0];
    int ans=dp[0];
    int cur_min=nums[0];


    for(int i=1;i<n;i++){

        if(nums[i]>=0){
            dp[i]=max(dp[i-1]*nums[i],nums[i]);
            cur_min=min(cur_min*nums[i], nums[i]);
        }
        else{
            int temp_max=max(cur_min*nums[i],nums[i]);
            cur_min=min(dp[i-1]*nums[i], nums[i]);
            dp[i]=max(temp_max,nums[i]);
        }
        ans=max(ans,dp[i]);
        
    }
    return ans;
} 


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n; cin>>n;
    vector<int>v(n);

    for(int i=0;i<n;i++){
    	cin>>v[i];
    }

    cout<<maxProduct(v);


    

    
    
    return 0;
}