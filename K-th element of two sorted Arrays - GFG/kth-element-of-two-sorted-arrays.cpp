//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        priority_queue<int> pq;
        
        int i=0;
        int j=0;
        int cnt=0;
        while(i<n && j<m){
            if(arr1[i]<arr2[j]){
                pq.push(arr1[i]);
                cnt++;
                i++;
            }
           else {
                pq.push(arr2[j]);
                cnt++;
                j++;
            }
            
            if(cnt == k)
            break;
        }
        
        while(cnt!=k && i<n){
             pq.push(arr1[i]);
                cnt++;
                i++;
        }
        
        while(cnt!=k && j<m){
             pq.push(arr2[j]);
                cnt++;
                j++;
        }
        return pq.top();
    }
};

//{ Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}
// } Driver Code Ends