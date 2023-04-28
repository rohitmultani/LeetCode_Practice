//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
  int findWays(vector<int> &num, int tar)
{

    int n = num.size();
    vector<vector<int>> dp(n,vector<int> (tar+1,0));

    for(int i=0;i<n;i++){
        dp[i][0]=1;
    }

    if(num[0]<=tar)
    dp[0][num[0]]=1;

    if(num[0] == 0) dp[0][0] = 2; 

    for(int ind=1;ind<n;ind++){
        for(int sum=0;sum<=tar;sum++){
                int notTake = dp[ind-1][sum];
                int take = 0;

                if(num[ind]<=sum)
                take=dp[ind-1][sum-num[ind]];

                dp[ind][sum]=(take+notTake);
        }
    }
    return dp[n-1][tar];
}
    int findTargetSumWays(vector<int>&arr ,int d) {
    int totSum=0;
    int n = arr.size();
    for(int i=0;i<n;i++){
        totSum+=arr[i];
    }

    if(totSum-d<0 || (totSum-d)%2) return false;

    return findWays(arr, (totSum-d)/2);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>arr(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>arr[i];
        }
        int target;
        cin >> target;

        Solution ob;
        cout<<ob.findTargetSumWays(arr,target);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends