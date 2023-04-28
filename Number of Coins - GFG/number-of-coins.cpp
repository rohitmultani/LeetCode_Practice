//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int minCoins(int nums[], int n, int x) 
	{ 
	    
    // vector<vector<int>> dp(n,vector<int>(x+1,0));
    vector<int> prev(x+1,0);
    vector<int> curr(x+1,0);
    for(int T=0;T<=x;T++){
        if(T%nums[0]==0)
        prev[T]=T/nums[0];

        else prev[T]=1e9;
    }

    for(int ind=1;ind<n;ind++){
        for(int T=0;T<=x;T++){
            int notTake = 0 + prev[T];
            int take = INT_MAX;
            if(nums[ind]<=T){
                take=1+curr[T-nums[ind]];
            }
             curr[T]=min(take,notTake);
        }
        prev=curr;
    }

    int ans = prev[x];

    if(ans>=1e9)
    return -1;

    return ans;
	} 
	  
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends