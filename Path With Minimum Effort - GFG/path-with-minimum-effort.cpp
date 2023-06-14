//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        
        priority_queue<pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        int diff=0;
        dist[0][0]=0;
        pq.push({0,{0,0}});
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        while(!pq.empty()){
            auto it = pq.top();
            int d = it.first;
            int row = it.second.first;
            int col = it.second.second;
            pq.pop();
            
            if(row==n-1 && col == m-1)
            return d;
            
            for(int i=0;i<4;i++){
                int nrow = row + dr[i];
                int ncol = col + dc[i];
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                    int di = abs(heights[nrow][ncol] - heights[row][col]);
                    int maxEffort = max(di,d);
                    if(dist[nrow][ncol]>maxEffort){
                    pq.push({maxEffort,{nrow,ncol}});
                    dist[nrow][ncol]=maxEffort;    
                    }
                }
            }
        }
        
        return 0;
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends