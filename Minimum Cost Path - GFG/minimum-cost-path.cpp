//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        
        vector<vector<int>> dist(n,vector<int> (n,1e9));
        vector<vector<int>> vis(n,vector<int>(n,0));
        
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        
        dist[0][0]=grid[0][0];
        
        pq.push({grid[0][0],{0,0}});
        
        int dr[4] = {-1,0,1,0};
        int dc[4] = {0,1,0,-1};
        
        while(!pq.empty()){
            auto it = pq.top();
            int d = it.first;
            int r = it.second.first;
            int c = it.second.second;
            pq.pop();
            vis[r][c]=1;
            
            for(int i=0;i<4;i++){
                int nr = r + dr[i];
                int cr = c + dc[i];
                
                if(nr>=0 && nr<n && cr>=0 && cr<n && vis[nr][cr]==0){
                    
                    if(d+grid[nr][cr]<dist[nr][cr]){
                     dist[nr][cr] = d+grid[nr][cr];
                    pq.push({dist[nr][cr],{nr,cr}});   
                    }
                     
                }
            }
        }
        
        return dist[n-1][n-1];
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
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends