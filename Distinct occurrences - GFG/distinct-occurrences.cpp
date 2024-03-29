//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
/*You are required to complete this method*/

class Solution
{
    public:
    int subsequenceCount(string s, string t)
    {
        int n = s.length();
        int m = t.length();
        // vector<vector<double>> dp(n+1,vector<double>(m+1,0));
        vector<int> prev(m+1,0);
        // vector<double> curr(m+1,0);

        // prev[0]=curr[0]=1;
        prev[0]=1;
        // for(int i=0;i<=n;i++)
        // dp[i][0]=1;

        // for(int i=1;i<=m;i++)
        // dp[0][i]=0;        

        for(int i=1;i<=n;i++){
            for(int j=m;j>=1;j--){
                if(s[i-1]==t[j-1])
                prev[j] = (prev[j-1] + prev[j])%1000000007;
                // else
                // prev[j]=prev[j];
            }
            
        }
        return prev[m]%1000000007;
    }
};
 


//{ Driver Code Starts. 

//  Driver code to check above method
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string tt;
		cin>>s;
		cin>>tt;
		
		Solution ob;
		cout<<ob.subsequenceCount(s,tt)<<endl;
		
		
	}
  
}
// } Driver Code Ends