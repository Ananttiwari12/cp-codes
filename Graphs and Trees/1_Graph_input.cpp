#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define ll long long

const int N= 1e5+1;

vector<int> gr[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m;
    cin>>n>>m;
    for(int i=0; i<m; i++){
        int x,y;
        cin>>x>>y;
        gr[x].push_back(y);
        gr[y].push_back(x);
    }
    
    return 0;
}