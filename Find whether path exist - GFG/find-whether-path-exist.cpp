//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    int dr[4]={-1,0,1,0};
    int dc[4]={0,1,0,-1};
    bool dfs(int row, int col, vector<vector<int>> &grid,vector<vector<int>> &vis, int n, int m){
        vis[row][col]=1;
        
        if(grid[row][col]==2)
        return true;
        
        for(int i=0;i<4;i++){
            int nrow = row + dr[i];
            int ncol = col + dc[i];
            
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0 && grid[nrow][ncol]!=0 ){
                 if(dfs(nrow,ncol,grid,vis,n,m))
                 return true;
            }
        }
        
        
        
    }
    
    bool is_Possible(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n,vector<int> (m,0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    return dfs(i,j,grid,vis,n,m);
                }
            }
        }
        return true;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}
// } Driver Code Ends