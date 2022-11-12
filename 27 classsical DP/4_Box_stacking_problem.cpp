#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

bool compare(vector<int>b1,vector<int>b2){
    return b1[2]<b2[2];
}

bool canplace(vector<int>b1, vector<int>b2){
    if(b1[0]<b2[0] and b1[1]<b2[1] and b1[2]<b2[2]) return true;
    return false;
}

int boxstacking(vector<vector<int>>boxes){
    int n=boxes.size();

    sort(boxes.begin(),boxes.end(),compare);

    vector<int>dp(n+1);

    for(int i=0;i<n;i++){
        dp[i]=boxes[i][2];
    }

    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(canplace(boxes[j],boxes[i])){
                int current_height=boxes[i][2];
                if(dp[j]+current_height>dp[i]){
                    dp[i]=dp[j]+current_height;
                }
            }
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        ans=max(ans,dp[i]);
    }
    return ans;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<vector<int>>boxes={
        {2, 1, 2},
        {3, 2, 3},
        {2, 2, 8},
        {2, 3, 4},
        {2, 2, 1},
        {4, 4, 5}
    };

    vector<vector<int>>boxes2={
        {50, 45, 20},
        {95, 37, 53},
        {45, 23, 12}
    };
    
    // int height=boxstacking(boxes);
    int height=boxstacking(boxes);
    cout<<height<<endl;
    return 0;
}

