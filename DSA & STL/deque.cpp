#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    deque<int>dq(10);
    for(int i=0;i<10;i++){
        dq[i]=i*i;
    }
    for(auto x: dq){
        cout<<x<<" ";
    }
    cout<<endl;
    cout<<"The size of deque is"<<endl;
    dq.push_back(100);
    dq.push_front(8);
    for(auto x: dq){
        cout<<x<<" ";
    }
    cout<<endl;
    cout<<dq.size()<<endl;
    dq.pop_back();
    dq.pop_front();
    for(int i=0;i<dq.size();i++){
        cout<<dq[i]<<" ";
    }
    return 0;
}