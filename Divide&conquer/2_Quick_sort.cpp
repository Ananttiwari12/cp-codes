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

void Quicksort(vector<int>&arr, int s, int e){
// base case
if(s>=e) return;

// rec case

int p=partition(arr,s,e);

Quicksort(arr,s,p-1);
Quicksort(arr,p+1,e);

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int>a{5,4,3,2,1};
    int s=0;
    int e=a.size()-1;

    Quicksort(a,s,e);
    for(int x:a){
        cout<<x<<" ";
    }
    return 0;
}