#include<bits/stdc++.h>
using namespace std;

int distributeCandies(vector<int> candies) {
   map<int, int>mp;
   int n=candies.size();
   for(int i=0;i<n;i++){
       mp[candies[i]]++;
   }
   int ans=0;
   for(auto x: mp){
    
    ans+=x.first;
   }
   return ans/2+((n/2)-(ans/2));
}
int main(int argc, char const *argv[])
{
    vector<int>b={6,6,2,2,3,3};
    cout<<distributeCandies(b);
    return 0;
}
