#include<bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    list<int>*l;
    public:
    Graph(int v){
        V=v;
        l=new list<int>[V];
    }
    void addEdge(int i, int j, bool undir=true){
        l[i].push_back(j);
        if(undir){
            l[j].push_back(i);
        }
    }
    
    void printadjlist(){
        int ans=0;
        for(int i=0;i<V;i++){
            cout<<i<<"-->";
            for(auto node: l[i]){
                cout<<node<<",";
            }
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


    int BFS(int source){
        
        queue<int>q;
        bool *visited= new bool[V]{0};
        vector<int>res;
        q.push(source);
        visited[source]=true;
        int count=0;
        while(!q.empty()){
            int f=q.front();
            count++;
            q.pop();

            for(auto nbr: l[f]){
                if(!visited[nbr]){
                    q.push(nbr);
                    visited[nbr]=true;
                }
            }
        }
        
        return count;
    }

  

};

int count_pairs(int n, vector<pair<int,int> > astronauts){
    Graph g(n);
     vector<pair<int,int> > ::iterator it=astronauts.begin();
    for(auto it=astronauts.begin();it!=astronauts.end();it++){
        auto x= it->first;
        auto y=it->second;
        g.addEdge(x,y);
    }
    
    // g.printadjlist();
    cout<<endl;
    int a=g.BFS(it->first);
    return a*(n-a);
    
}
int main(int argc, char const *argv[])
{
    int n; cin>>n;
    vector<pair<int, int>>astronauts={{0,1},{2,3},{0,4}};
    cout<<count_pairs(n,astronauts);

    return 0;
}
