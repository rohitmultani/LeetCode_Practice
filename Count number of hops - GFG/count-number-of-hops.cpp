//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define M 1000000007
class Solution
{
    public:
    
    long long f(int i,int n,vector<long long> &dp){
        if(i>n)
        return 0;
        
        if(i==n)
        return 1;
        
        if(dp[i]!=-1)
        return dp[i];
        
        long long ways=0;
        for(int j=1;j<=3;j++){
            ways=ways+f(i+j,n,dp)%M;
        }
        
        return dp[i]=ways%M;
    }
    
    long long countWays(int n)
    {
        vector<long long> dp(n+1,-1);
        return f(0,n,dp);
        
    }
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends