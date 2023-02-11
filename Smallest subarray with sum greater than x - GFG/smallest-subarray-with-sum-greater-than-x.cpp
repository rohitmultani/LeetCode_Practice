//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:

    int smallestSubWithSum(int arr[], int n, int x)
    {
        int start=0;
        int end=-1;
        int currSum=0;
        int len=n;
        bool isAns=false;
        while(start<n && end<n){
            if(currSum<=x){
                end++;
                currSum+=arr[end];
            }
            else{ 
                isAns=true;
                len=min(len,end-start+1);
                currSum-=arr[start];
                start++;
            }
        }
        if(isAns)
        return len;
        else return 0;
    }
};

//{ Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n,x;
		cin>>n>>x;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution obj;
		cout<<obj.smallestSubWithSum(a,n,x)<<endl;
	}
	return 0;
}
// } Driver Code Ends