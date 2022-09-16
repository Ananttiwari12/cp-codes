#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> nums) {
        // sort(nums.begin(),nums.end());
    int sum=0;vector<int>v;
    while(nums.size()!=1){
    sort(nums.begin(),nums.end());
        if(nums.size()==1){
           
            sum+=nums[0];
        }
        else
        v.push_back(nums[0]);
        v.push_back(nums[1]);
        sum=nums[0]+nums[1];
        nums.erase(nums.begin());
        nums.erase(nums.begin());
        nums.push_back(sum);
        }
        
    int ans=0;
    for(int i=0;i<v.size();i++){
        ans +=v[i];
    }
    
    return ans;
}
int main(int argc, char const *argv[])
{
    vector<int>v{1,2,3,4,5};
    cout<<solve(v);
    return 0;
}
