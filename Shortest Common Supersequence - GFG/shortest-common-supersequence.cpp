//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    //Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string s1, string s2, int m, int n)
    {
        int x = s1.length();
        int y = s2.length();

        vector<vector<int>> dp(x+1,vector<int> (y+1));
        
        for(int i=0;i<x+1;i++)
        dp[i][0]=0;
        
        for(int j=0;j<y+1;j++)
        dp[0][j]=0;
        
        for(int i=1;i<=x;i++){
            for(int j=1;j<=y;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else {
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        
        return x + y - dp[x][y];
        // string ans = "";
        // int i=x,j=y;
        // while(i>0 && j>0){
        //     if(s1[i-1]==s2[j-1]){
        //         ans += s1[i-1];
        //         i--;
        //         j--;
        //     }   
        //     else if(dp[i-1][j]>dp[i][j-1]){
        //         ans+=s1[i-1];
        //         i--;
        //     }
        //     else{
        //         ans+=s2[j-1];
        //         j--;
        //     }
        // }

        // while(i>0){
        //     ans+=s1[i-1];
        //     i--;
        // }
        // while(j>0){
        //     ans+=s2[j-1];
        //     j--;
        // }

        // reverse(ans.begin(),ans.end());
        // return ans;

    }
};

//{ Driver Code Starts.

int main()
{   
    
    int t;
    
    //taking total testcases
    cin >> t;
    while(t--){
    string X, Y;
    //taking String X and Y
	cin >> X >> Y;
	
	//calling function shortestCommonSupersequence()
	Solution obj;
	cout << obj.shortestCommonSupersequence(X, Y, X.size(), Y.size())<< endl;
    }
	return 0;
}


// } Driver Code Ends