#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define ll long long

class Node{
public:
    string name;
    list<string>nbrs;

    Node(string name){
        this->name=name;
    }
};

class Graph{

    // all nodes
    // hashmap (string, node*)

    unordered_map<string, Node*> m;
    
public:
    Graph(vector<string>cities){

        for(auto city : cities){
            m[city]= new Node(city);
        }
    }

    void addEdge(string x, string y, bool undir=false){
        m[x]->nbrs.push_back(y);

        if(undir){
            m[y]->nbrs.push_back(x);
        }
    }

    void printAdjlist(){

        for(auto citypair: m){
            auto city=citypair.first;
            Node *node = citypair.second;
            cout<<city<<"-->";
            
            for(auto nbr: node->nbrs){
                cout<<nbr<<",";
            }
            cout<<endl; 
        }
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<string> city={"Delhi","Paris","Newyork","London"};
    Graph g(city);

    g.addEdge("Delhi","London");
    g.addEdge("Delhi","Paris");
    g.addEdge("Newyork","London");
    g.addEdge("Paris","Newyork");

    g.printAdjlist();

    
    return 0;
}