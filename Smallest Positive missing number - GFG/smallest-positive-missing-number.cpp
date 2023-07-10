//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n) 
    { 
      int maxi=INT_MIN;
      for(int i=0;i<n;i++){
          maxi=max(maxi,arr[i]);
      }
      if(maxi<=0)
      return 1;
      vector<bool> st(maxi,false);
      
      for(int i=0;i<n;i++){
          if(arr[i]>0){
              st[arr[i]]=true;
          }
      }
      int ans=-1;
      for(int i=1;i<st.size();i++){
          if(!st[i]){
              ans = i;
              break;
          }
      }
      if(ans==-1)
      return maxi+1;
      return ans;
    } 
};

//{ Driver Code Starts.

int missingNumber(int arr[], int n);

int main() { 
    
    //taking testcases
    int t;
    cin>>t;
    while(t--){
        
        //input number n
        int n;
        cin>>n;
        int arr[n];
        
        //adding elements to the array
        for(int i=0; i<n; i++)cin>>arr[i];
        
        Solution ob;
        //calling missingNumber()
        cout<<ob.missingNumber(arr, n)<<endl;
    }
    return 0; 
} 
// } Driver Code Ends