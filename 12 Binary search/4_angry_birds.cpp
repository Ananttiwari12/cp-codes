#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define ll long long

bool canplacebirds(int size, int B,vector<int>nests,int sep){

int birds=1;
int location=nests[0];
for(int i=1;i<size;i++){
    int current_location=nests[i];
    if(current_location-location>=sep){
        birds++;
        location=current_location;
        if(birds==B){
            return true;
        }
    }
}
return false;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int B=3;
    vector<int> nests{1,2,4,8,9};
    sort(nests.begin(), nests.end());
    int n=nests.size();

    int s=nests[0];
    int e=nests[n-1];
    int ans=-1;
    while (s<=e){
    
        int mid=(s+e)/2;
        bool canplace=canplacebirds(n,B,nests,mid);
        if(canplace){
            s=mid+1;
            ans=mid;
        }
        else{
            e=mid-1;
        }
    }
    cout<<ans;

    return 0;
}






