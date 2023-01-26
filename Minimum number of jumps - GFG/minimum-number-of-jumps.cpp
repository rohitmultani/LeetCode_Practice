//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int nums[], int n){
        int numOfJumps = 0, currentIntervalEnd = 0, farthestReachFoundSoFar = 0;
        if(nums[0]==0)
        return -1;
        
        for(int i = 0 ; i < n - 1 ; i++) {     
                                                         
            farthestReachFoundSoFar = max(farthestReachFoundSoFar, i + nums[i]);
                                                                                    
            if(i == currentIntervalEnd) {              
                numOfJumps++;                          
                currentIntervalEnd = farthestReachFoundSoFar;   
            }                 
            
            if(i == farthestReachFoundSoFar)
            numOfJumps=-1;
        }                                                
        return numOfJumps;// Your code here
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends