#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define ll long long

// FOR SUMMATION

struct segmenttrees{

    vector<int>st;
    int n;
    void intit(int _n){
        this->n=_n;
        st.resize(4*n,0);
    }

    void build(int start, int ending, int node, vector<int>&v){
        // leaf nodes base cases
        if(start==ending){
            st[node]=v[start];
            return;
        }

        int mid=(start+ending)/2;

        // left subtree is start to mid
        build(start, mid, 2*node+1 ,v);

        // right suntree is mid+1 to ending
        build(mid+1, ending, 2*node+2, v);

        st[node]=st[node*2+1]+st[node*2+2];
    }

    int Query(int start, int ending, int l, int r, int node){
        // no overlapping case
        if(start>r || ending<l){
            return 0;
        }

        // complete overlapping case
        if(start>=l && ending<=r){
            return st[node];
        }

        // partial overlapping case
        int mid=(start+ending)/2;
        int q1=Query(start, mid, l ,r,2*node+1);
        int q2=Query(mid+1, ending, l ,r,2*node+2);
        return q1+q2;
    }

    void update(int start, int ending, int node, int index,int value){
        // base case
        if(start==ending){
            st[node]=value;
            return;
        }
        int mid=(start+ending)/2;
        if(index<=mid){
            // left subtree
            update(start, mid, 2*node+1, index, value);
        }
        else{
            // right subtree
            update(mid+1, ending, 2*node+2, index, value);
        }
        st[node]=st[node*2+1]+st[node*2+2];
        return;
    }

    void build(vector<int>&v){
        build(0, n-1, 0, v);
    }

    int Query(int l, int r){
       return Query(0, n-1, l, r, 0);
    }

    void update(int x, int y){
        update(0, n-1, 0, x, y);
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int>v={1,2,3,4,5,6,7,8};

    segmenttrees tree;
    tree.intit(v.size());
    tree.build(v);
    cout<<tree.Query(0,4)<<endl;
    tree.update(4,10);
    cout<<tree.Query(2,6)<<endl;
    tree.update(2,20);
    cout<<tree.Query(4,4)<<endl;   
    return 0;
}