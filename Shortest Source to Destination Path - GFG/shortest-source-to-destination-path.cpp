//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        vector<vector<int>> dist(N,vector<int> (M,1e9));
        vector<vector<int>> vis(N,vector<int> (M,0));
        
        if(A[0][0]==0)
        return -1;
       queue<pair<int,pair<int,int>>> q;
        
        q.push({0,{0,0}});
        
        
        
        int dr[4]={-1,0,1,0};
        int dc[4]={0,1,0,-1};
        
        while(!q.empty()){
            auto it=q.front();
            int steps = it.first;
            int r = it.second.first;
            int c = it.second.second;
            
            
            // cout<<r<<" "<<c<<endl;
            vis[r][c]=1;
            q.pop();
            
            if(r==X && c==Y)
            return steps;
            
            for(int i=0;i<4;i++){
                int newr = r + dr[i];
                int newc = c + dc[i];
                
                if(newr>=0 && newr<N && newc>=0 && newc<M && vis[newr][newc]==0 && 
                A[newr][newc]==1){
                    if(steps + 1 < dist[newr][newc]){
                        dist[newr][newc]=steps+1;
                        q.push({steps + 1,{newr,newc}});
                    }
                }
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends