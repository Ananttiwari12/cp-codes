#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define ll long long

int chartodigit(char ch){
    return ch-'0';
}
char digittochar(int x){
    return x+'0';
}

string addition(string n1, string n2){

    // making sure n2 is greater than n1
    if(n1.length()>n2.length())
    swap(n1,n2);

    string result="";
    
    //reversing the string to make calculaton easier
    reverse(n1.begin(),n1.end());
    reverse(n2.begin(),n2.end());

    int carry=0;
    for(int i=0;i<n1.length();i++){
        int d1=chartodigit(n1[i]);
        int d2=chartodigit(n2[i]);
        int sum=d1+d2+carry;
        int outputdigit=sum%10;
        carry=sum/10;
        result.push_back(digittochar(outputdigit));
    }   

    // after the size of n1 is full
    for(int i=n1.length();i<n2.length();i++){
        int d2=chartodigit(n2[i]);
        int sum=d2+carry;
        int outputdigit=sum%10;
        carry=sum/10;
        result.push_back(digittochar(outputdigit));
    }

    // if a carry exist
    if(carry) result.push_back('1');

    //reversing the final result
    reverse(result.begin(),result.end());
    return result;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n; cin>>n;
string s[n];
for(int i=0;i<n;i++){
    cin>>s[i];
}

string s1=addition(s[0],s[1]);
string s2=addition(s[2],s[3]);
string s3=addition(s1,s2);
cout<<addition(s3,s[4]);

    return 0;
}   