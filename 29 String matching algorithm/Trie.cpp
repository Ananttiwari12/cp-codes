#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long


struct node{
    node* next[26];
    bool is_end;
    node(){
        for(int i=0;i<26;i++){
            next[i]=NULL;
            is_end=false;
        }
    }
};

struct Trie{
node* root;

void insert_trie(string s){
    node* curr=root;
    for(int i=0;i<s.length();i++){
        int imap=s[i]-'a';
        // new node
        if(curr->next[imap]==NULL){
            curr->next[imap]=new node();
        }
        // go to that node
        curr=curr->next[imap];
    }
    curr->is_end=true;
}

bool search_trie(string s){
    node* curr=root;
    for(int i=0;i<s.length();i++){
        int imap=s[i]-'a';
        if(curr->next[imap]==NULL)return false;
        curr=curr->next[imap];
    }
    return curr->is_end;
}
};
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    struct Trie trie;
    trie.root =new node();

    int n; cin>>n;
    
    for(int i=0;i<n;i++){
        string s; cin>>s;
        trie.insert_trie(s);
    }
    
    string pat;
    cin>>pat;
    
    if(trie.search_trie(pat)){
        cout<<"FOUND"<<endl;
    }
    else{
        cout<<"NOT FOUND"<<endl;
    }

    
    return 0;
}
