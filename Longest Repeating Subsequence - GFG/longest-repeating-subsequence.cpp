//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		int LongestRepeatingSubsequence(string str){
        int x = str.length();
        int y = str.length();

        vector<vector<int>> dp(x+1,vector<int> (y+1));
        
        for(int i=0;i<x+1;i++)
        dp[i][0]=0;
        
        for(int j=0;j<y+1;j++)
        dp[0][j]=0;
        
        for(int i=1;i<=x;i++){
            for(int j=1;j<=y;j++){
                if(str[i-1]==str[j-1] && i!=j){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else {
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[x][y];
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends