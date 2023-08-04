//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    private:
     void topo(int node, vector<pair<int,int>> adj[],int vis[],stack<int> &st){
        vis[node]=1;
        
        for(auto it:adj[node]){
        int v = it.first;
        if(!vis[v]){
            topo(v,adj,vis,st);
        }
        }
        st.push(node);
    }
    public:
      vector <int> maximumDistance(vector<vector<int>> edges,int N,int e,int src)
      {
            vector<pair<int,int>> adj[N];
        
        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
        }
        
        int vis[N]={0};
        stack<int> st;
        
        
        for(int i=0;i<N;i++){
            if(!vis[i])
            topo(i,adj,vis,st);
        }
        
        vector<int> dist(N,INT_MIN);
        
        dist[src]=0;
        
        while(!st.empty()){
            int node = st.top();
            st.pop();
            if(dist[node]!=INT_MIN)
            for(auto it:adj[node]){
                int v = it.first;
                int wt = it.second;
                
                if(dist[node]+wt>dist[v])
                dist[v]=dist[node]+wt;
            }
        }
        
        for (int i = 0; i < N; i++) {
        if (dist[i] == 1e9) dist[i] = INT_MIN;
        }
        return dist;
      }
};

//{ Driver Code Starts.

int main() {
  
    int t;
    cin>>t;
    while(t--)
    {

        int v,e;
        cin>>v>>e;
     
        int src;
        cin>>src;
        vector<vector<int>> edges(e,vector<int> (3));
        for(auto &j:edges)
          cin>>j[0]>>j[1]>>j[2];

        Solution s;
        vector <int> ans=s.maximumDistance(edges,v,e,src);
        for(auto j:ans)
        {
            if(j==INT_MIN)
              cout<<"INF ";
            else
              cout<<j<<" ";
        }
        cout<<endl;
    } 
    return 0;
 
}
// } Driver Code Ends