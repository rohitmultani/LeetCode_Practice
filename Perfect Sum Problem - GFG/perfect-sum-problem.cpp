//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


# define M 1000000007
class Solution{
    
	public:
	int f(int i,int arr[], int sum,vector<vector<int>> &dp){
	    if(i==0){
	        if(sum==0 && arr[0]==0)
	        return dp[i][sum]=2;
	       else if(sum==0 || sum==arr[0])
	        return dp[i][sum]=1;
	        
	        else return dp[i][sum]=0;
	    }
	    
	    if(dp[i][sum]!=-1)
	    return dp[i][sum];
	    
	    int notake = f(i-1,arr,sum,dp);
	    
	    int take = 0;
	    
	    if(arr[i]<=sum)
	    take=f(i-1,arr,sum-arr[i],dp);
	    
	    
	    return dp[i][sum]=(take+notake)%M;
	}
	int perfectSum(int arr[], int n, int sum)
	{
	    vector<vector<int>> dp(n,vector<int> (sum+1,0));
	    
	    
	    for(int i=0;i<n;i++){
	        for(int j = 0;j<=sum;j++){
	            if(i==0){
	                if(j==0 && arr[0]==0)
	                 dp[i][j]=2;
	                else if(j==0 || j==arr[0])
	                dp[i][j]=1;
	            }
	            else{
	                
	            
	            int notake = dp[i-1][j];
	    
	            int take = 0;
	    
        	    if(arr[i]<=j)
        	    take=dp[i-1][j-arr[i]];
	    
	             dp[i][j]=(take+notake)%M;
	            }
	        }
	    }
        return dp[n-1][sum];
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends