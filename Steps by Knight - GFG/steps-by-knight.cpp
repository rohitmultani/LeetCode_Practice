//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    vector<vector<int>> vis(N+1,vector<int> (N+1,0));
	    queue<pair<int,pair<int,int>>> q;
	    q.push({0,{KnightPos[0],KnightPos[1]}});
	    vis[KnightPos[0]][KnightPos[1]]=1;
	    
	    int mini = INT_MAX;
	    bool flag = false;
	    int dr[] = {-1,1,1,-1,-2,2,2,-2};
	    int dc[] = {-2,-2,2,2,-1,-1,1,1};
	    while(!q.empty()){
	        auto it = q.front();
	        int step = it.first;
	        int row = it.second.first;
	        int col = it.second.second;
	        q.pop();
	        
	       // cout<<row<<" "<<col<<endl;
	        
	        if(row==TargetPos[0] && col==TargetPos[1]){
	            return step;
	        }
	        
	        for(int i=0;i<8;i++){
	            int nrow = row + dr[i];
	            int ncol = col + dc[i];
	            
	            if(nrow>=1 && nrow<=N && ncol>=1 && ncol<=N && vis[nrow][ncol]==0){
	                vis[nrow][ncol]=1;
	                q.push({step+1,{nrow,ncol}});
	            }
	        }
	    }
	    
	    
	    return -1;
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends