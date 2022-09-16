#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

class Graph{
    int V;
    list<pair<int,int>>l;

public:
    Graph(int V){
        this->V=V;
    }

    void addEdge(int u, int v){
        l.push_back(make_pair(u,v));
    }

    int find_set(int i, int parent[]){
        if(parent[i]==-1){
            return i;
        }

        //path compression optimisation
        return parent[i]=find_set(parent[i],parent);
    }

    void union_set(int x, int y, int parent[]){
        int s1=find_set(x, parent);
        int s2= find_set(y, parent);

        if(s1!=s2){
            parent[s1]=s2;
        }
    }

    bool contain_cycles(){
        int *parent= new int[V];

        for(int i=0; i<V;i++){
            parent[i]=-1;
        }

        for(auto edge: l){
            int x=edge.first;
            int y=edge.second;

            int s1=find_set(x,parent);
            int s2=find_set(y,parent);

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
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,0);

    cout<<g.contain_cycles()<<endl;

    return 0;
}