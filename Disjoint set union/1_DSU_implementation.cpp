// cycle detection in undirected graph using DSU

#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

class Graph{

    int V;
    list<pair<int, int>>l;

public:

    Graph(int V){
        this->V=V;
    }
    void addedge(int u, int v){
        l.push_back(make_pair(u,v));
    }

    // Find
    int find_set(int i, int parent[]){
        // base
        if(parent[i]==-1){
            return i;
        }
        return find_set(parent[i],parent);
    }

    // union
    void union_set(int x ,int y, int parent[]){
        int s1= find_set(x,parent);
        int s2= find_set(y, parent);

        if(s1!=s2){
            parent[s1]= s2;
        }
    }

    bool contain_cycle(){

        // DSU logic to check if graph contains cycles or not
        int *parent= new int[V];

        for(int i=0;i<V;i++){
            parent[i]=-1;
        }
        // iterate over edge list
        for(auto edges: l){
            int i=edges.first;
            int j=edges.second;

            int s1=find_set(i,parent);
            int s2=find_set(j,parent);

            if(s1!=s2){
                union_set(s1,s2,parent);
            }
            else{
                cout<<"same parents "<<s1<<" and "<<s2<<endl;
                return true;
            }
        }
        delete [] parent;
        return false;
    }
};

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Graph g(4);
    g.addedge(0,1);
    g.addedge(1,2);
    g.addedge(2,3);
    g.addedge(3,0);

    cout<<g.contain_cycle()<<endl;
    
    
    return 0;
}