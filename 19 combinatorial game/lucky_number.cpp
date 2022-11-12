#include<bits/stdc++.h>
using namespace std;


int main(){
ios_base:: sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);

int t; cin>>t;
while(t--){
    
   int n; cin>>n;
   int a, b; cin>>a>>b;
   int A[n];
   for(int i=0;i<n;i++){
       cin>>A[i];
   }
    
     unsigned long long int bob=0; unsigned long long int alice=0; unsigned long long int both=0;
    for(unsigned long long int i=0;i<n;i++){
        if((A[i])%a==0) bob++;
        if((A[i])%b==0) alice++;
        if((A[i])%(a*b)==0) both++;
    }
    if(a!=b){
         if(both==0){
        if(bob>alice) cout<<"BOB"<<endl;
        else if(alice>bob) cout<<"ALICE"<<endl;
        else cout<<"ALICE"<<endl;
         }
         else {
        if((both+bob)>alice) cout<<"Bob"<<endl;
        else cout<<"Alice"<<endl;
    }
    }
    
    else{
        
        if(bob%2==0) cout<<"ALICE"<<endl;
        else cout<<"BOB"<<endl;
    }
}
    
    return 0;
}