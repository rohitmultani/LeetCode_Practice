//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int maxWeight, int weight[], int value[], int n) 
    { 
    vector<int> prev(maxWeight+1,0);
	vector<int> curr(maxWeight+1,0);
	for(int i=weight[0];i<=maxWeight;i++)
	prev[i]=value[0];

	for(int ind=1;ind<n;ind++){
		for(int W=0;W<=maxWeight;W++){
			int notTake= 0 + prev[W];
			int take=INT_MIN;
			if(weight[ind]<=W)
			take=value[ind] + prev[W-weight[ind]];

			curr[W]=max(take,notTake);
		}
		prev=curr;
	}
	return prev[maxWeight];
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends