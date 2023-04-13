//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
  public:
  void inorder(vector<int> &A,int n,int index,vector<int> &inOrd){
      if(index>=n)
      return;
      
      inorder(A,n,2*index+1,inOrd);
      inOrd.push_back(A[index]);
      inorder(A,n,2*index+2,inOrd);
  }
  int minS(vector<int>&nums)
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
    int minSwaps(vector<int>&A, int n){
        vector<int> inOrd;
        int index=0;
        inorder(A,n,index,inOrd);
        
        return minS(inOrd);
    }
    
    
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<int>A(n);
	    for(int i = 0 ; i < n; i++){
	        cin >> A[i];
	    }
	    Solution ob;
	    int ans = ob.minSwaps(A, n);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends