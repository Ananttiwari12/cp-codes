#include<bits/stdc++.h>
using namespace std;

void changeposition(vector<int>&arr, int n, int idx){
    for(int i=idx;i<n;i++){
        if(arr[i]==1) arr[i]=0;
        else arr[i]=1;
    }
}
int solve(int n, vector<int> a){
    int count=1;
    for(int i=0;i<n;i++){
        if(a[i]==0){
            changeposition(a,n,i);
            a[i]=1;
            count++;
        }
        else continue;
    }
    return count+  1;
 }
 int main(int argc, char const *argv[])
 {
    vector<int>a{0,1,0,1};
    cout<<solve(4,a);
    return 0;
 }
 