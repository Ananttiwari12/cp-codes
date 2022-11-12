// single source shortest path algorithm for undirected graph

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
        l=new list<int> [V];
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
            for(auto node : l[i]){
                cout<<node<<",";
            }
            cout<<endl;
        }
    }

    void BFS(int source, int dest=-1){

        queue<int>q;
        bool *visited= new bool[V]{0};

        // creating a distance and parent array
        int *distance= new int[V]{0};
        int *parent= new int[V];

        for (int i =0; i<V; i++){
            parent[i]=-1;
        }
        

        parent[source]=source;
        distance[source]=0;

        q.push(source);
        visited[source]=true;

        while(!q.empty()){
         int f=q.front();
        cout<<f<<endl;
        q.pop();
            for(auto nbr: l[f]){
                if(visited[nbr]!=true){
                    q.push(nbr);
                    
                    // parent and distance
                    parent[nbr]= f;
                    distance[nbr]= distance[f]+1;
                    visited[nbr]=true;
                }
            }
        }
        // print the shortest distance

        for(int i=0; i<V;i++){
            cout<<"The shortest distance to path "<<i<<" is "<<distance[i]<<endl;
        }

        // print the path from source to destination
        if(dest!=-1){
            int temp=dest;
            while(temp!=source){
                cout<<temp<<"--";
                temp=parent[temp];
            }
            cout<<source<<endl;
        }
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
    g.BFS(1,6);

    return 0;
}