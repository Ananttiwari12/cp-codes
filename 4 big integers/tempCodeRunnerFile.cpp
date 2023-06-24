// #include<bits/stdc++.h>
// #define endl "\n"
// using namespace std;
// #define mod 1000000007
// #define ll long long

// int chartodigit(char ch){
//     return ch-'0';
// }
// char digittochar(int x){
//     return x+'0';
// }

// string addition(string n1, string n2){

//     // making sure n2 is greater than n1
//     if(n1.length()>n2.length())
//     swap(n1,n2);

//     string result="";
    
//     //reversing the string to make calculaton easier
//     reverse(n1.begin(),n1.end());
//     reverse(n2.begin(),n2.end());

//     int carry=0;
//     for(int i=0;i<n1.length();i++){
//         int d1=chartodigit(n1[i]);
//         int d2=chartodigit(n2[i]);
//         int sum=d1+d2+carry;
//         int outputdigit=sum%10;
//         carry=sum/10;
//         result.push_back(digittochar(outputdigit));
//     }   

//     // after the size of n1 is full
//     for(int i=n1.length();i<n2.length();i++){
//         int d2=chartodigit(n2[i]);
//         int sum=d2+carry;
//         int outputdigit=sum%10;
//         carry=sum/10;
//         result.push_back(digittochar(outputdigit));
//     }

//     // if a carry exist
//     if(carry) result.push_back('1');

//     //reversing the final result
//     reverse(result.begin(),result.end());
//     return result;
// }


// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);
    
//     int n; cin>>n;
// string s[n];
// for(int i=0;i<n;i++){
//     cin>>s[i];
// }

// string s1=addition(s[0],s[1]);
// string s2=addition(s[2],s[3]);
// string s3=addition(s1,s2);
// cout<<addition(s3,s[4]);

//     return 0;
// }   


#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define int long long


#define mod 1000000007


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // #endif

    int n; cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    vector<int>ans;
            int cnt=0;
        for(int j=0;j<n-1;j++){
            if(abs(a[j]-a[j+1])!=1){
                cnt++;
                break;
            }
        }

    if(cnt==0){
        for(int i=0;i<n;i++){
            cout<<a[i]<<" ";
        }
        return 0;
    }


    for(int i=0;i<n-1;i++){
        ans.push_back(a[i]);
        
        int cnt=0;
        for(int j=i+1;j<n-1;j++){
            if(abs(a[i]-a[i+1])!=1){
                cnt++;
                break;
            }
        }

        if(cnt==0){
            for(int j=i+1;j<n;j++){
                ans.push_back(a[j]);
            }
            break;
        }

        if(a[i]>a[i+1]){
            for(int j=a[i]-1;j>=a[i+1]+1;j--){
                ans.push_back(j);
            }

            // cout<<"one ";
        }
        if(a[i]<a[i+1]){
            for(int j=a[i]+1;j<=a[i+1]-1;j++){
                ans.push_back(j);
            }

            // cout<<"Sec ";
        }


    }

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }

    
    
    return 0;
}