#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define ll long long

// will merge the sorted vector
int merge(vector<int>&arr, int s,int e){

    int i=s;
    int mid=(s+e)/2;
    int j=mid+1;

    vector<int> temp;

    int counter=0;

    while(i<=mid && j<=e){

// this will work untill any of the side get exhausted
    if(arr[i]<arr[j]){
        temp.push_back(arr[i]);
        i++;
    }
    else{
        counter+=(mid-i+1);
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
        return counter;
    }


// will sort the vector
int inversion_count(vector<int>&arr, int s, int e){

// base case
    if(s>=e){
        return 0;
    }

// rec case
    int mid=(s+e)/2;
    int c1=inversion_count(arr,s,mid);
    int c2=inversion_count(arr,mid+1,e);
    int cross_inversion=merge(arr,s,e);

    return c1+c2+cross_inversion;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> a{0,5,2,3,1};
    int s=0;
    int e=a.size()-1;

    cout<<inversion_count(a,s,e)<<endl;

    return 0;
}