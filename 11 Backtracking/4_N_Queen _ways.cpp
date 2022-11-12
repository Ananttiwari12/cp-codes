#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define ll long long

bool canPlace(int board[][20],int n,int x,int y){
    //checking column if there is queen present or not
    for(int k=0;k<x;k++){
        if(board[k][y]==1){
            return false;
        }
    }

    // checking left diagonal if there is queen present or not
    int i=x;
    int j=y;
    while(i>=0 and j>=0){
        if(board[i][j]==1){
            return false;
        }
        i--;j--;
    }

    // checking right diagonal if there is queen present or not
    i=x;j=y;
    while(i>=0 and j<n){
        if(board[i][j]==1){
            return false;
        }
        i--;
        j++;
    }
    return true;
}

void printBoard(int board[][20],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
        cout<<endl;
}

int solveNqueen(int n, int board[][20],int i){
    // base case
    if(i==n){
        // printBoard(board, n);
        return 1;
    }
    //rec case
    // try to place queen in every row
    int no_of_ways=0;
    for(int j=0;j<n;j++){
        // checking whether current i j position is safe or not
        if(canPlace(board,n,i,j)){
            board[i][j]=1;
            no_of_ways+=solveNqueen(n,board,i+1);
            
            // backtracking
            board[i][j]=0;
        }
    }
    return no_of_ways;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;cin>>n;
    int board[20][20]={0};
    
    cout<<"No of ways are: "<<solveNqueen(n,board,0);
    return 0;
}