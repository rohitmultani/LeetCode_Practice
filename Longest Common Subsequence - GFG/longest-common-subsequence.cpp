//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int f(int ind1,int ind2, string s1, string s2,vector<vector<int>> &dp){
        if(ind1<0 || ind2<0)
        return 0;
        
        if(dp[ind1][ind2]!=-1)
        return dp[ind1][ind2];
        
        
        if(s1[ind1]==s2[ind2]){
            return dp[ind1][ind2]=1 + f(ind1-1,ind2-1,s1,s2,dp);
        }
        else{
            return dp[ind1][ind2]=max(f(ind1-1,ind2,s1,s2,dp),f(ind1,ind2-1,s1,s2,dp));
        }
    }
    int lcs(int n, int m, string s1, string s2)
    {
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        
        for(int ind1=1;ind1<=n;ind1++){
            for(int ind2=1;ind2<=m;ind2++){
                if(s1[ind1-1]==s2[ind2-1])
                    dp[ind1][ind2]=1 + dp[ind1-1][ind2-1];
                else
                dp[ind1][ind2]=max(dp[ind1-1][ind2],dp[ind1][ind2-1]);
    
            }
        }
        return dp[n][m];
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(n, m, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends