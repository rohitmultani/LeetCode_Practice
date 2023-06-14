//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
        vector<pair<int,int>> adj[n];
        
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        
        // {stops,node,cost}
        queue<pair<int,pair<int,int>>> q;
        //why q? 
        // ans even movement of steps storing in increasing order
        q.push({0,{src,0}});
        vector<int> dist(n,1e9);
        dist[src]=0;
        
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;
            
            if(stops>K) continue;
            for(auto iter:adj[node]){ 
                // this is with respect to adj list
                int adjNode = iter.first;
                int w = iter.second;
                
                if(cost + w < dist[adjNode] && stops<=K){
                    dist[adjNode] = cost + w;
                    q.push({stops+1,{adjNode,cost+w}});
                }
            }
        }
        
        if(dist[dst]==1e9) return -1;
        return dist[dst];
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends