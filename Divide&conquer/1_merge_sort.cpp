#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define ll long long

// will merge the sorted vector
void merge(vector<int>&arr, int s,int e){

    int i=s;
    int mid=(s+e)/2;
    int j=mid+1;

    vector<int> temp;

    while(i<=mid && j<=e){

// this will work untill any of the side get exhausted
    if(arr[i]<arr[j]){
        temp.push_back(arr[i]);
        i++;
    }
    else{
        temp.push_back(arr[j]);
        j++;
    }
    }

    // filling remaining array
    while(i<=mid){
        temp.push_back(arr[i]);
        i++;
    }
    while(j<=e){
        temp.push_back(arr[j]);
        j++;
    }

    // copying all elements of temp in original array
    int k=0;
    for(int idx=s;idx<=e;idx++){
        arr[idx]=temp[k++];
        }
        return;
    }


// will sort the vector
void mergesort(vector<int>&arr, int s, int e){

// base case
    if(s>=e){
        return;
    }

// rec case
    int mid=(s+e)/2;
    mergesort(arr,s,mid);
    mergesort(arr,mid+1,e);

    return merge(arr,s,e);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> a{5,4,3,2,1};
    int s=0;
    int e=a.size()-1;

    mergesort(a,s,e);

    for(int i=s;i<=e;i++){
        cout<<a[i]<<" ";
    }  
    return 0;
}