#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

const int N=10000;
vector<int>gr[N];
int visited[N];
int dist[N];

void bfs(int source){
    queue<int>q;
    q.push(source);
    visited[source]=1;
    dist[source]=0;

    while(!q.empty()){
        int f=q.front();
        q.pop();
        for(auto nbr: gr[f]){
            if(!visited[nbr]){
                q.push(nbr);
                visited[nbr]=1;
                dist[nbr]=dist[f]+1;
            }
        }
    }
}

bool isPrime(int n){
    for(int i=2; i*i<=n;i++){
        if(n%i==0)return false;
    }
    return true;
}
bool ifdiff_by_one(int a, int b){
    int count=0;
    while(a){
        int i=a%10;
        int j=b%10;
        if(i!=j)count++;
        a/=10;
        b/=10;
    }
    if(count==1)return true;
    return false;
}

void buildGraph(){
    vector<int>primes;
    for(int i=1000;i<=9999;i++){
        if(isPrime(i))primes.push_back(i);
    }
    for(int i=0; i<primes.size();i++){
        for(int j=i+1;j<primes.size();j++){
            int a= primes[i];
            int b= primes[j];

            if(ifdiff_by_one(a,b)){
                gr[a].push_back(b);
                gr[b].push_back(a);
            }
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t; cin>>t;
    
    buildGraph();
    
        
    while(t--){
        int a,b; cin>>a>>b;

        for(int i=1000; i<=9999;i++){
            dist[i]=-1;
            visited[i]=0;
        }

        bfs(a);
        if(dist[b]==-1)cout<<"IMPOSSIBLE"<<endl;
        else cout<<dist[b]<<endl;   
    }
    return 0;
}