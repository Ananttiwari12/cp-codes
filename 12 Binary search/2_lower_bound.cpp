#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define ll long long

int lower_occurences(vector<int>a, int key){
    // int size=a.size();
    int s=0; int e=a.size()-1;
    int mid;
    int ans=-1;
    while(s<=e){
        mid=(s+e)/2;
        if(key==a[mid]){
            ans=mid;
            e=mid-1;
        }
        else if(key<a[mid]){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    return ans;
}

int upper_occurences(vector<int>a, int key){
    // int size=a.size();
    int s=0; int e=a.size()-1;
    int mid;
    int ans=-1;
    while(s<=e){
        mid=(s+e)/2;
        if(key==a[mid]){
            ans=mid;
            s=mid+1;
        }
        else if(key>a[mid]){
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    vector<int>arr={0,1,1,2,3,4,4,4,4,56};

    int key; cin>>key;

    cout<<lower_occurences(arr,key)<<endl;
    cout<<upper_occurences(arr,key)-lower_occurences(arr,key);

    return 0;
}