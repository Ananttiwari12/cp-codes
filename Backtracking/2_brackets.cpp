#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define ll long long

void generate(string output,int n,int open ,int close, int i){
    // base case
    if(i==2*n){
        cout<<output<<endl;
        return;
    }
    // place closing brackets
    if(open>close){
        generate(output+')',n,open,close+1,i+1);
    }
    // place open brrackets
    if(open<n){
        generate(output+'(',n,open+1,close,i+1);
    }

}

// 0r

void generate_2(string output,int n,int open ,int close, int i){
    // base case
    if(i==2*n){
        cout<<output<<endl;
        return;
    }
    // place closing brackets
    if(open>close){
        output+=')';
        generate_2(output,n,open,close+1,i+1);

        output.pop_back(); //--> to trace the original string : backtracing
    }
    // place open brrackets
    if(open<n){
        output+='(';
        generate_2(output,n,open+1,close,i+1);

        output.pop_back();  //--> to trace the original string : backtracing
    }

}




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n; cin>>n;
    string output;

    // generate(output,n,0,0,0);
    generate_2(output,n,0,0,0);

    return 0;
}