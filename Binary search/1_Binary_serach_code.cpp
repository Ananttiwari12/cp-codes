#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define ll long long

int binary_search(int x, int a[],int n){

int s=0;
int e=n;
int mid;
while(s<=e){

mid=(s+e)/2;

if(x<a[mid]) e=mid-1;
else if(x>a[mid]) s=mid+1;
else return mid;

}
return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int arr[]={1,5,7,19,3,6,65,4,30};
    int x; cin>>x;

    int n=sizeof(arr)/sizeof(arr[0]);
    sort(arr,arr+n);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<binary_search(x,arr,n);

    return 0;
}