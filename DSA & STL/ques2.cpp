#include<bits/stdc++.h>
using namespace std;
int firstUniqChar(string s) {
        for(int i=0;i<s.length()-1;i++){
            for(int j=i+1;j<s.length();j++)
            if(s[i]==s[j]){
               continue;
            }
            else if((s[i]==s[j]) && (i==s.length()) && (j==s.length())){
                return -1;
            }
            else
            {
            return i;
            break; 
        }
        }
}
int main(){
    string s="aabb";
    int c=firstUniqChar(s);
    cout<<c;
    return 0;
}