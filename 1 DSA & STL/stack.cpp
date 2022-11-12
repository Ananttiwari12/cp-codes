#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    stack<string>books;
    books.push("c++");
    books.push("c");
    books.push("java");
    books.push("python");

    cout<<books.size()<<endl;

    while(!books.empty()){
        cout<<books.top()<<endl;
        books.pop();
    }
    
    return 0;
}