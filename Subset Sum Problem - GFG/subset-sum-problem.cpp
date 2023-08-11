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
        vector<vector<bool>> dp(n,vector<bool> (sum+1,false));
        vector<bool> prev(sum+1,false);
        vector<bool> curr(sum+1,false);
        
        if(arr[0]<=sum)
        prev[arr[0]]=true;
        
        
            prev[0]=true;
        
        
        for(int i=1;i<n;i++){
            for(int target = 1;target<=sum;target++){
                bool take = false;
                if(arr[i]<=target)
                take = prev[target-arr[i]];
        
                bool nottake = prev[target];
                curr[target]=take || nottake;
                
               
            }
             prev=curr;
        }
        
        return prev[sum];
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