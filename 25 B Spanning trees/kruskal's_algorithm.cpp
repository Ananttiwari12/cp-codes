// #include<bits/stdc++.h>
// #define endl "\n"
// using namespace std;
// #define mod 1000000007
// #define int long long

// struct edge{
//     int a,b,w;
// };
// edge arr[100001];
// int par[100001];

// bool compare(edge a, edge b){
//     if(a.w<b.w) return true;
//     else return false;
// }

// void merge(int a, int b){
//     par[a]=b;
// }
// int find(int a){
//     if(par[a]==-1) return a;
//     return find(par[a]);
// }

// int32_t main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);

//     int n,m; cin>>n>>m;

//     for(int i=1;i<=n;i++) par[i]=-1;

//     for(int i=0;i<m;i++){
//         cin>>arr[i].a>>arr[i].b>>arr[i].w;
//     }
//     sort(arr,arr+m,compare);

//     int sum=0;

//     for(int i=0;i<m;i++){
//         int a=find(arr[i].a);
//         int b=find(arr[i].b);

//         if(a!=b){
//             sum+=arr[i].w;
//             merge(a,b);
//         }
//         else{
//             continue;
//         }
//     }
//     cout<<sum<<endl;

//     return 0;
// }


#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

struct edge{
    int a,b,w;
};

edge ar[100001];
int par[100001];

bool compare(edge a, edge b){
    if(a.w<b.w) return true;
    return false;
}

int find(int a){
    if(par[a]==-1) return a;
    return find(par[a]);
}
void merge(int a, int b){
    par[a]=b;
    }



int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m; cin>>n>>m;
    for(int i=1;i<=n;i++) par[i]=-1;

    for(int i=0;i<m;i++){
        cin>>ar[i].a>>ar[i].b>>ar[i].w;
    }

    sort(ar,ar+m,compare);
    int sum=0;
    for(int i=0;i<m;i++){
        int a= find(ar[i].a);
        int b=find(ar[i].b);

        if(a!=b){
            sum+=ar[i].w;
            merge(a,b);
        }
        else continue;
    }

    
    return 0;
}