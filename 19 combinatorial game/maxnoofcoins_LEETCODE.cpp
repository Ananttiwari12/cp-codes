#include<bits/stdc++.h>
using namespace std;

int maxCoins(vector<int> piles){
    int n=piles.size();
    sort(piles.begin(),piles.end());
    int ans=0;int cnt=0;
    for(int i=n-2;i>=0;i-=2){
        ans+=piles[i];
        cnt++;
        if(cnt*3==n) break;

    }
    return ans;
}
int main(int argc, char const *argv[])
{
    vector<int>piles={2,4,1,2,7,8};
    cout<<maxCoins(piles);
    return 0;
}
