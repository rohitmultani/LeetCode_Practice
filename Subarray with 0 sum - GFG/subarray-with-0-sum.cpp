//{ Driver Code Starts
// A C++ program to find if there is a zero sum
// subarray
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    //Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(int arr[], int n)
    {
        vector<int> prefix(n);
        unordered_map<int,int> mp;
        int prefixSum=0;
        int count=0;
        for(int i=0;i<n;i++){
            prefixSum+=arr[i];
            prefix[i]=prefixSum;
        }
        mp[0]=1;
        for(int i=0;i<n;i++){
            int element=prefix[i]-0;
            if(mp.find(element)!=mp.end()){
                return true;
            }
            mp[prefix[i]]++;
        }
        return false;
    }
};

//{ Driver Code Starts.
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    Solution obj;
	    	if (obj.subArrayExists(arr, n))
		cout << "Yes\n";
	else
		cout << "No\n";
	}
	return 0;
}
// } Driver Code Ends