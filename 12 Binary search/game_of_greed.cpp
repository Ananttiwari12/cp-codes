#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define ll long long

bool can_partition(int a[], int n, int k,int min_coins){

    int partition=0;
    int current_friend=0;
    for(int i=0;i<n;i++){
        if(current_friend+a[i]>=min_coins){
            partition++;
            current_friend=0;
        }
        else{
            current_friend+=a[i];
        }
    }

    return partition>=k;
}

int partition(int a[],int n, int k){
    int s=a[0];
    int e=0;

    for(int i=0;i<n;i++){
        e+=a[i];
    }

    int ans;
    while (s<=e){
        
    int mid=(s+e)/2;
        bool if_can_partition= can_partition(a,n,k,mid);
        if(if_can_partition){
            ans=mid;
            s=mid+1;
        }
        else {
            e=mid-1;
        }
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int a[]={10,20,30,40};
    int n=sizeof(a)/sizeof(int);

    int k=3; // no of partition

    cout<<partition(a,n,k);

    return 0;
}