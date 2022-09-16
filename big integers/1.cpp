#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int chartoint(char a){
    return a-'0';
}
char inttochar(int a){
    return a+'0';
}

string adddition(string s1,string s2){
    
    if(s1.length(),s2.length()){
        swap(s1,s2);
    }
    
    reverse(s1.begin(),s1.end());
    reverse(s2.begin(),s2.end());
    
    string result="";
    
    int carry=0;
    for(int i=0;i<s1.length();i++){
        int d1=chartoint(s1[i]);
        int d2=chartoint(s2[i]);
       int sum=d1+d2+carry;
       int outputdigit=sum%10;
        carry=sum/10;
        result.push_back(inttochar(outputdigit));
    }
    
    for(int i=s1.length();i<s2.length();i++){
        int d2=chartoint(s2[i]);
        int sum=d2+carry;
        int outputdigit=sum%10;
        carry=sum/10;
        result.push_back(inttochar(outputdigit));
        
    }
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
string res="";
for(int i=0;i<n-2;i=i+2){

res+=adddition(s[i],s[i+1]);

}
    cout<<res<<endl;
    return 0;
}