#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

const int N=1001;
vector<pair<int,int>>gr[N];

int dijikstra(int src, int dest, int n){

    vector<int>dist(N,INT_MAX);
    set<pair<int,int>>s;
    dist[src]=0;
    s.insert({0,src});

    while(!s.empty()){

        auto it=s.begin();
        int Node=it->second;
        int dist_till_now= it->first;
        s.erase(it);

        for(auto nbr_pair:gr[Node]){

            int nbr=nbr_pair.second;
            int curEdge= nbr_pair.first;

            if(dist_till_now+curEdge<dist[nbr]){
                
                auto f= s.find({dist[nbr],nbr});
                if(f!=s.end()){
                    s.erase(f);
                }
                dist[nbr]= dist_till_now + curEdge;
                s.insert({dist[nbr],nbr});
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<dist[i]<<endl;;
    }
    return dist[dest];
}



int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m; cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y,w;
        cin>>x>>y>>w;
        gr[x].push_back({w,y});
        gr[y].push_back({w,x}); //assuming undirected graph 
    } 
    int a,b; cin>>a>>b;
    cout<<dijikstra(a,b,1)<<endl;

    return 0;
}