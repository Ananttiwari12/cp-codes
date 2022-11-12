#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

void overlaynumber(char arr[], int number){
    int j=0;
    while(number){
        if(number&1){
            cout<<arr[j];
        }
        j++;
        number>>=1;
    }
    cout<<endl;
}

void generateSubsets(char a[]){
    int n=strlen(a);
    for(int i=0;i<(1<<n);i++){
        overlaynumber(a,i);
    }
    return;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    char arr[1000];
    cin>>arr;

    generateSubsets(arr);

    
    return 0;
}