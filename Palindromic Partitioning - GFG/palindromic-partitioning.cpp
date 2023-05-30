//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
bool isPal(int i,int j, string &s){
    while(i<j){
        if(s[i]!=s[j])
        return false;
        
        i++;
        j--;
    }
    return true;
}
int f(int i,int n, string &str,vector<int> &dp){
    if(i==n) return 0;

    if(dp[i]!=-1)
    return dp[i];
    int minCost = INT_MAX;

    for(int j=i;j<n;j++){
        if(isPal(i,j,str)){
           int cost = 1+f(j+1,n,str,dp);
            minCost = min(minCost,cost);
        }
    }
    return dp[i]=minCost;
}
    int palindromicPartition(string str)
    {
        int n = str.size();
    vector<int> dp(n+1,0);
    for(int i=n-1;i>=0;i--){
  
    int minCost = INT_MAX;

    for(int j=i;j<n;j++){
        if(isPal(i,j,str)){
           int cost = 1+dp[j+1];
            minCost = min(minCost,cost);
        }
    }
     dp[i]=minCost;
    }
    return dp[0]-1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends