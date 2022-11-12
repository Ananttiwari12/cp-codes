#include<bits/stdc++.h>
using namespace std;

int firstUniqChar(string s) {
    
    int n=s.length();
        map<char, int>mp;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }
        int cnt=0;
        char uni;
        for(auto x: mp){
            if(x.second==1){
                cnt++;
                uni=x.first;
                break;
            }
        }
        int ans;
        if(cnt==0) ans=-1;
        else{
            for(int i=0;i<n;i++){
                if(s[i]==uni){
                    ans=i;
                    break;
                }
            }
        }
        return ans;
}
int main(int argc, char const *argv[])
{
    string s="leetcode";
    cout<<firstUniqChar(s);
    return 0;
}
