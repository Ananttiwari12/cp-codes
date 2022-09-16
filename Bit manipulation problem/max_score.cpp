#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define ll long long

void matrixScore(vector<vector<int>> grid) {
    
    int n=grid.size();
    
    for(int i=0; i<n;i++){
    	if(grid[i][0]==0){
    	for(int j=0; j<grid[i].size();j++){
    		grid[i][j]^=1;
    	}
    }
    }
    
  for(int i=0; i<grid[0].size();i++){
        int cntz=0;
        int cnto=0;
    		for(int j=0;j<grid.size();j++){
    			if(grid[j][i]==0)cntz++;
    			else cnto++;
    		}
    		if(cntz>cnto){
    		    for(int j=0;j<grid.size();j++){
    			grid[j][i]^=1;
    			
    		}
    		}
    }

    int ans[n]={0};
    for(int i=0; i<grid.size();i++){
    	int k=0;
    	for(int j=grid[0].size()-1; j>=0;j--){
    		ans[i]+=grid[i][j]*pow(2,k);
    		k++;
    	}
    }

    int sum=0;
    for(int i=0;i<n;i++){
    	sum+=ans[i];
    }
    cout<<sum;
}

int main(){

	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);	

    vector<vector<int>>v={{0,0,1,1},{1,0,1,0},{1,1,0,0}};
    matrixScore(v);
  
    return 0;
}