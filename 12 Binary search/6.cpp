#include<bits/stdc++.h>
using namespace std;

bool can_eat(vector<int>v, int h, int m){
    if(v[m]<=h){
        return true;
    }
    else return false;
    
    
}
int minEatingSpeed(vector<int> piles, int h) {
    
    int s=0;
    int e=piles.size()-1;
    while(s<=e){
        if(s==e){
            return piles[s];
        }
        int mid=(s+e)/2;
        bool caneat=can_eat(piles, h,mid);
        if(caneat){
            s=mid+1;
        }
        else e=mid-1;
    }
    
}
int main(int argc, char const *argv[])
{
    vector<int>v={30,11,23,4,20};
    cout<<minEatingSpeed(v,5);
    return 0;
}
