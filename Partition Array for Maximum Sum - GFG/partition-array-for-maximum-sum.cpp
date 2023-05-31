//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int f(int ind,vector<int> &num, int k,vector<int> &dp){
        int n = num.size();
        if(ind==n) return 0;

        if(dp[ind]!=-1)
        return dp[ind];

        int len = 0;
        int maxi = INT_MIN;
        int maxiAns = INT_MIN;

        for(int j = ind; j<min(ind+k,n);j++){
            len++;
            maxi = max(maxi,num[j]);
            int sum = len*maxi + f(j+1,num,k,dp);
            maxiAns = max(maxiAns,sum);
        }
        return dp[ind]=maxiAns;
    }
    int solve(int n, int k, vector<int>& arr){

        vector<int> dp(n+1,0);

        for(int ind=n-1;ind>=0;ind--){
        int len = 0;
        int maxi = INT_MIN;
        int maxiAns = INT_MIN;

        for(int j = ind; j<min(ind+k,n);j++){
            len++;
            maxi = max(maxi,arr[j]);
            int sum = len*maxi + dp[j+1];
            maxiAns = max(maxiAns,sum);
        }
         dp[ind]=maxiAns;
        }

        return dp[0];
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        vector<int> arr;
        
        for(int i=0; i<n; ++i){
            int x; cin>>x;
            arr.push_back(x);
        }
        
        Solution obj;
        cout<<obj.solve(n,k,arr)<<"\n";
    }
    return 0;
}
// } Driver Code Ends