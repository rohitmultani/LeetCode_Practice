//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	void pushZerosToEnd(int arr[], int n) {
	    int zeroPos = -1;
	    int nonZero = -1;
	    
	    for(int i=0;i<n;i++){
	        if(zeroPos==-1 && arr[i]==0){
	            zeroPos = i;
	        }
	        if(zeroPos!=-1 && nonZero==-1 && arr[i]!=0){
	            nonZero = i;
	        }
	        
	        if(zeroPos!=-1 && nonZero!=-1)
	        {
	            swap(arr[zeroPos],arr[nonZero]);
	            nonZero=-1;
	            zeroPos++;
	        }
	    }
	    
	    
	}
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.pushZerosToEnd(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends