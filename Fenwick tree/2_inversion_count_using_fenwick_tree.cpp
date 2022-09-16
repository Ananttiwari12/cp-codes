#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define ll long long

struct fenwick{

vector<int> fn;
int n;
void init(int n){
    this->n=n+1;
    fn.resize(this->n,0);
}

void add(int x, int y){
    x++; // 1 based index
    while(x<n){
        fn[x]+= y;
        x+= x& (-x); // last set bit : adding last set bit of x to itself
    }
}

int sum(int x){

    x++; // 1 based index
    int ans=0;
    while(x){
        ans+=fn[x];
        x-= x & (-x); // climbing to the parent
    }
    return ans;
}

int sum(int l, int r){
    return sum(r)-sum(l-1);
}

};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n; cin>>n;
    pair<int, int> a[n];
    for(int i=0;i<n;i++){
        cin>>a[i].first;
        a[i].second=i;
    }

    sort(a, a+n);

    fenwick tree;
    tree.init(n);

    int inversion_count=0;
    for(int i=0;i<n;i++){

        int element=a[i].first;
        int index=a[i].second;

        inversion_count+= tree.sum(index+1, n-1);
        tree.add(index,1);
    }

    cout<<inversion_count<<endl;
    
    return 0;
}