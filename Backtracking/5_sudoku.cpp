#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define ll long long

bool isSafe(int mat[][9], int n,int i,int j,int no){
// checking rows and columns
for(int k=0;k<9;k++){
    if(mat[k][j]==no  || mat[i][k]==no){
        return false;
    }
}
// checking subgrids
int sx=(i/3)*3;
int sy=(j/3)*3;
for(int x=sx; x<sx+3; x++){
    for(int y=sy; y<sy+3; y++){
        if(mat[x][y]==no){
            return false;
        }
    }
}
return true;
}



bool solvesudoku(int mat[][9], int n, int i, int j){
// base case
if(i==n){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    return true;
}
// rec case
// at the corners
if(j==n){
    return solvesudoku(mat,n,i+1,0);
}

// skip the element if the matrix is not empty
if(mat[i][j]!=0){
    return solvesudoku(mat,n,i,j+1);
}

// trying every numbers
for(int no=1;no<=n;no++){

    // check if it is safe to put number
    if(isSafe(mat,n,i,j,no)){
        mat[i][j]=no;
    bool solvesubprob=solvesudoku(mat,n,i,j+1);
    if(solvesubprob==true){
        return true;
        }
     }
}
// backtracking: if the no is failed to satisfy
mat[i][j]=0;
return false;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    

    int n=9;
    int mat[9][9]=
    {{5,3,0,0,7,0,0,0,0},
    {6,0,0,1,9,5,0,0,0},
    {0,9,8,0,0,0,0,6,0},
    {8,0,0,0,6,0,0,0,3},
    {4,0,0,8,0,3,0,0,1},
    {7,0,0,0,2,0,0,0,6},
    {0,6,0,0,0,0,2,8,0},
    {0,0,0,4,1,9,0,0,5},
    {0,0,0,0,8,0,0,7,0}};

    if(!solvesudoku(mat,n,0,0)){
        cout<<"No solution exists!";
    }

    return 0;
}