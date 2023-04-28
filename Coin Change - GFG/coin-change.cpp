//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long int count(int den[], int n, int value) {

          vector<vector<long>> dp(n,vector<long>(value+1,0));
          vector<long long int> prev(value+1,0);
          vector<long long int> curr(value+1,0);
          for(int target=0;target<=value;target++){
              prev[target]=target%den[0]==0;
          }
        
          for(int ind=1;ind<n;ind++){
              for(int T=0;T<=value;T++){
                    long long int notTake = prev[T];
                    long long int take = 0;
                    if(den[ind]<=T){
                        take=curr[T-den[ind]];
            }
             curr[T]=take+notTake;
              }
              prev=curr;
          }
          return prev[value];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends