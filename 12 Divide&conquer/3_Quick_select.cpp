
// PROGRAM TO FIND Kth SMALLEST ELEMENT

#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define ll long long

int partition(vector<int>&arr, int s, int e){

    int pivot=arr[e];
    int i=s-1;
    for (int j =s; j< e; j++)
    {
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[e]);
    return i+1;
}

int QuickSelect(vector<int>arr, int s, int e, int k){

    int p=partition(arr,s,e);
    if(p==k) return arr[p];
    
    else if(k<p){
        return QuickSelect(arr,s,p-1,k);
    }
    else return QuickSelect(arr,p+1,e,k);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int>a{5,4,3,2,1};
    int k; cin>>k;
    int n=a.size();

    // taking 0th based index
    cout<<QuickSelect(a,0,n-1,k);
    return 0;
}