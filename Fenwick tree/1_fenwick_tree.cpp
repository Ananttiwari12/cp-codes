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

    vector<int>v={1,2,3,4,5,6,7};

    fenwick tree;
    tree.init(v.size());

    for(int i=0;i<v.size();i++){
        tree.add(i, v[i]);
    }

    cout<<tree.sum(3,5)<<endl;
    tree.add(4,-5);
    cout<<tree.sum(3,5);
    
    return 0;
}