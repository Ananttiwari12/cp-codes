#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define ll long long

class Graph{

    int V;
    list<int> *l;
public:
    Graph(int v){
        V=v;
        l= new list<int>[V];
    }

    void addEdge(int i, int j, bool undir=true){
        l[i].push_back(j);
        if(undir){
            l[j].push_back(i);
        }
    }

    void printAdjlist(){
        for(int i=0;i<V;i++){
            cout<<i<<"-->";
            for(auto node: l[i]){
                cout<<node<<",";
            }
            cout<<endl;
        }
    }


    void DFShelper(int Node, bool *visited){
        visited[Node]= true;

        cout<<Node<<",";
        for(auto nbr: l[Node]){
            if(!visited[nbr]){
                DFShelper(nbr,visited);
            }
        }
            return;
    }


    void DFS(int source){
        bool *visited= new bool[V]{0};
        DFShelper(source, visited);
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

     Graph g(7);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,5);
    g.addEdge(5,6);
    g.addEdge(4,5);
    g.addEdge(0,4);
    g.addEdge(3,4);

    g.printAdjlist();
    cout<<endl;
    g.DFS(1);
    
    return 0;
}