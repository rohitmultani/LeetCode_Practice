//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int k){
    int n = arr.size();
    vector<bool> prev(k+1,false);
    vector<bool> curr(k+1,false);
    
    prev[0]=true;
    curr[0]=true;

    prev[arr[0]]=true;
    
    for(int ind=1;ind<n;ind++){
        for(int target=1;target<=k;target++){
            bool notTake = prev[target];
            bool take = false;

            if(arr[ind]<=target)
            take = prev[target-arr[ind]];

            curr[target]=take|notTake;
        }
        prev=curr;
    }
    
    return prev[k];
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends