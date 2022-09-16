#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define ll long long

void findingsubsets(char *input, char *output, int i, int j){
//Base case
if(input[i]=='\0'){
    output[j]='\0';
if(output[0]=='\0'){
    cout<<"NULL";
}
cout<<output<<endl;
return;
}
// Recursive case
// including ith index of input
output[j]=input[i];
findingsubsets(input,output,i+1,j+1);

// excluding ith index of input
findingsubsets(input, output,i+1,j);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    char input[100],output[100];
    cin>>input;
    findingsubsets(input, output, 0, 0);
    
    return 0;
}