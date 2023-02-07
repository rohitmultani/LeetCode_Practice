//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    vector<int> nextGreater(int arr[],int n){
    vector<int> ans(n);
    ans[0]=arr[0];
    for(int i=1;i<n;i++){
        ans[i]=max(ans[i-1],arr[i]);
    }
    return ans;
    }
   
    vector<int> prevGreater(int arr[],int n){
    vector<int> ans(n);
    ans[n-1]=arr[n-1];
    for(int i=n-2;i>=0;i--){
        ans[i]=max(ans[i+1],arr[i]);
    }
    return ans;
    }
    long long trappingWater(int arr[], int n){
        
        vector<int> next(n);
        next=nextGreater(arr,n);
        vector<int> prev(n);
        prev=prevGreater(arr,n);
        long long water=0;
        
        for(int i=0;i<n;i++){
            if(next[i]==-1 || prev[i]==-1){
                continue;
            }
            else{
                water=water+min(prev[i],next[i]) - arr[i];
            }
        }
        return water;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends