//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int cutRod(int price[], int n) {
        vector<int> prev(n+1,0);
	// vector<int> curr(n+1,0);
	for(int N=0;N<=n;N++){
		prev[N]=N*price[0];
	}

	for(int ind=1;ind<n;ind++){
		for(int N=0;N<=n;N++){
			int notTake = 0 + prev[N];
			int take = INT_MIN;
			int rodlen = ind + 1;
			if(rodlen <= N)
			take = price[ind] + prev[N-rodlen];

			prev[N]=max(notTake,take);
		}
		
	}
	return prev[n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends