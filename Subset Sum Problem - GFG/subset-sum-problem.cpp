//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool f(int i, vector<int> arr, int sum,vector<vector<int>> &dp){
        
        if(sum==0)
        return true;
        
        if(i==0)
        return sum == arr[i];
        
        if(dp[i][sum]!=-1)
        return dp[i][sum];
        
        bool take = false;
        if(arr[i]<=sum)
        take = f(i-1,arr,sum-arr[i],dp);
        
        bool nottake = f(i-1,arr,sum,dp);
        
        return  dp[i][sum]=take | nottake;
        
    }
    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        vector<vector<int>> dp(n,vector<int> (sum+1,-1));
        return f(n-1,arr,sum,dp);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends