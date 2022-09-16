#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define ll long long

class Graph{

    int V;
    list<int>*l;

    public:
    Graph(int v){
        V=v;
        l = new list<int>[v];  // dynamically creating array of list
    }

    void addEdge(int i, int j, bool undir=true){
        l[i].push_back(j);

        if(undir) 
            l[j].push_back(i);  // if graph is undirected
    }

    void printAdjlist(){

        // Iterate over all rows
        for(int i=0;i<V;i++){
            cout<<i<<"--> ";
            // iterating over all elements of ith linked list
            for(auto node : l[i]){
                cout<<node<<",";
            }
            cout<<endl;
        }
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Graph g(6);
    g.addEdge(0,1);
    g.addEdge(0,4);
    g.addEdge(2,1);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(2,3);
    g.addEdge(3,5);

    g.printAdjlist();
    
    return 0;
}