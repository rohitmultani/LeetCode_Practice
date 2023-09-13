//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

bool isValid(int i,int j,int n,int m){
    if(i>=0 && i<n && j>=0 && j<m)
    return true;
    
    return false;
}
    int f(int i,int j,vector<vector<int>> M,int n, int m, vector<vector<int>> &dp){
        
        if(i<0 || i==n || j==m)
        return 0;
        
        if(dp[i][j]!=-1)
        return dp[i][j];
        
        int one = f(i-1,j+1,M,n,m,dp);
        int two = f(i,j+1,M,n,m,dp);
        int three = f(i+1,j+1,M,n,m,dp);
        
        return dp[i][j]=M[i][j]+max(one,max(two,three));
        
    }
    
    int collectGold(vector<vector<int>> gold, int x, int y, int n, int m, vector<vector<int>> &dp) {
 
    // Base condition.
    if ((x < 0) || (x == n) || (y == m)) { 
        return 0;
    }
   
    if(dp[x][y] != -1){
        return dp[x][y] ;
    }
 
    // Right upper diagonal
    int rightUpperDiagonal = collectGold(gold, x - 1, y + 1, n, m, dp);
 
     // right
    int right = collectGold(gold, x, y + 1, n, m, dp);
 
    // Lower right diagonal
    int rightLowerDiagonal = collectGold(gold, x + 1, y + 1, n, m, dp); 
 
    // Return the maximum and store the value
    return dp[x][y] = gold[x][y] + max(max(rightUpperDiagonal, rightLowerDiagonal), right); 
}
 
    int maxGold(int m, int n, vector<vector<int>> gold)
    {
        
       int goldTable[m][n];
    memset(goldTable, 0, sizeof(goldTable));
 
    for (int col=n-1; col>=0; col--)
    {
        for (int row=0; row<m; row++)
        {
            // Gold collected on going to the cell on the right(->)
            int right = (col==n-1)? 0: goldTable[row][col+1];
 
            // Gold collected on going to the cell to right up (/)
            int right_up = (row==0 || col==n-1)? 0:
                            goldTable[row-1][col+1];
 
            // Gold collected on going to the cell to right down (\)
            int right_down = (row==m-1 || col==n-1)? 0:
                             goldTable[row+1][col+1];
 
            // Max gold collected from taking either of the
            // above 3 paths
            goldTable[row][col] = gold[row][col] +
                              max(right, max(right_up, right_down));
                                                     
        }
    }
 
    // The max amount of gold collected will be the max
    // value in first column of all rows
    int res = goldTable[0][0];
    for (int i=1; i<m; i++)
        res = max(res, goldTable[i][0]);
    return res;

    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}
// } Driver Code Ends// code here