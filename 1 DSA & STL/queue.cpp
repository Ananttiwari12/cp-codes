#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    queue<int>q;
    q.push(10);
    q.push(9);
    q.push(8);
    q.push(7);
    q.emplace(90);
    q.push(6);
    cout<<q.back()<<endl;

    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }

    return 0;
}