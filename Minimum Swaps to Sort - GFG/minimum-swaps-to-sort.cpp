//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	   int n = nums.size();
	   vector<pair<int,int>> temp;
	   
	   for(int i=0;i<n;i++){
	       temp.push_back({nums[i],i});
	   }
	   
	   
	   int cnt=0;
	   sort(temp.begin(),temp.end());
	   
	   for(int i=0;i<n;i++){
	       if(temp[i].second!=i){
	           cnt++;
	           swap(temp[i],temp[temp[i].second]);
	           i--;
	       }
	       
	   }
	   
	   return cnt;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends