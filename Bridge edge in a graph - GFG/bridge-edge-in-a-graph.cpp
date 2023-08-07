//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	int timer = 1;
    void dfs(int node, int parent, vector<int> &vis,
             vector<int> adj[], int tin[], int low[], vector<vector<int>> &bridges) {
        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer++;
        for (auto it : adj[node]) {
            if (it == parent) continue;
            if (vis[it] == 0) {
                dfs(it, node, vis, adj, tin, low, bridges);
                low[node] = min(low[it], low[node]);
                // node --- it
                if (low[it] > tin[node]) {
                    //it is a bridge
                    bridges.push_back({it, node});
                }
            }
            else {
                low[node] = min(low[node], low[it]);
            }
        }
    }
    //Function to find if the given edge is a bridge in graph.
    int isBridge(int n, vector<int> adj[], int c, int d) 
    {
        // vector<int> adj[n];
        // for(auto it:connections){
        //     adj[it[0]].push_back(it[1]);
        //     adj[it[1]].push_back(it[0]);
        // }

        vector<int> vis(n,0);
        int tin[n];
        int low[n];
        vector<vector<int>> bridges;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,-1,vis,adj,tin,low,bridges);
            }
        }
        for(auto it:bridges){
            if(it[0]==c && it[1]==d || it[0]==d && it[1]==c)
            return true;
        }
        
        return false;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}


// } Driver Code Ends