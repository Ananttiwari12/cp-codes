#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

int minSumOfLengths(vector<int>& arr, int target) {

        int n=arr.size();
        vector<int>pdp(n,INT_MAX);
        vector<int>sdp(n,INT_MAX);

        int i=0;
        int curr_sum=0;
        for(int j=0;j<n;j++){
            curr_sum+=arr[j];

            while(i<j and curr_sum>target){
                curr_sum-=arr[i];
                i++;
            }
            if(j-1<0)
                pdp[j]=INT_MAX;
            else pdp[j]=pdp[j-1];
               
            
            if(curr_sum==target){
                pdp[j]=min(pdp[j],j-i+1);
            }
            
        }

        int j=n-1;
        curr_sum=0;
        for(int i=n-1;i>=0;i--){
            curr_sum+=arr[i];

            while(i<j and curr_sum>target){
                curr_sum-=arr[j];
                j--;
            }
            if(i+1>=n)
                sdp[i]=INT_MAX;
            else sdp[i]=sdp[i+1];
               
            
            if(curr_sum==target){
                sdp[i]=min(sdp[i],j-i+1);
            }
            
        }

        int ans=INT_MAX;
        for(int i=0;i<n-1;i++){
            if(pdp[i]!=INT_MAX and sdp[i+1]!=INT_MAX)
            ans=min(ans, pdp[i]+sdp[i+1]);
        }

        if(ans==INT_MAX)return -1;
        else return ans;

        
    }

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    

    
    
    return 0;
}