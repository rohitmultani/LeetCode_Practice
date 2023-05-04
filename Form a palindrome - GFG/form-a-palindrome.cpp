//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int findMinInsertions(string s1){
        string s2 = s1;
        reverse(s2.begin(),s2.end());
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
        return x-dp[x][y];

    }
};

//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.findMinInsertions(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends