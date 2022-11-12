#include<bits/stdc++.h>
using namespace std;
#define int long long

struct segmenttrees{
    
    vector<int>st;
    int n;
    void init(int _n){
        this->n=_n;
        st.resize(4*n,0);
    }
    
    void build(int start, int ending, int node, vector<int>&v){
        if(start==ending){
            st[node]=v[start];
            return;
        }
        int mid=(start+ending)/2;
        build(start, mid, 2*node+1, v);
        build(mid+1, ending, 2*node+2, v);
        st[node]=min(st[2*node+1],st[2*node+2]);
    }
    
    int query(int start, int ending, int node, int l, int r){
        
        if(start>r || ending<l) return INT_MAX;
        if(start>=l && ending<=r) return st[node];
        
        int mid=(start+ending)/2;
        int q1=query(start, mid, 2*node+1, l,r);
        int q2=query(mid+1, ending, 2*node+2, l,r);
        
        int c=min(q1,q2);
        return c;
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
        st[node]=min(st[node*2+1],st[node*2+2]);
        return;
    }
    
    void build(vector<int>&v){
        build(0,n-1,0,v);
    }
    int query(int l, int r){
        return query(0, n-1, 0, l ,r);
    }
    void update(int x, int y){
        update(0, n-1, 0, x, y);
    }
    
};
vector<int> solve(int n, vector<int>arr, vector<vector<int>> queries){
    vector<int>res;
    segmenttrees tree;
    tree.init(arr.size());
    tree.build(arr);
    for(int i=0;i<queries.size();i++){
        if(queries[i][0]==1){
            tree.update(queries[i][1]-1,queries[i][2]);
        }
        else if(queries[i][0]==2){
            res.push_back(tree.query(queries[i][1]-1,queries[i][2])-1);
        }
    }
    return res;
    
}

int32_t main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n=8;
    vector<int>arr={3, 2, 4, 5, 1, 1, 5, 3};
    vector<vector<int>>queries={{2,1,4},{2, 5, 6},{1,2,3},{2,1,4}};
    vector<int>res=solve(n,arr,queries);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }

    
    return 0;
}
