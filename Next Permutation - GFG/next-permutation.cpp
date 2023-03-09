//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> nextPermutation(int N, vector<int> nums){

        if(N==1){
            return nums;
        }

        int pivot=-1;

        for(int i=N-1;i>0;i--){

            if(nums[i-1]<nums[i])
            {
                pivot=i-1;
                break;
            }

        }

        if(pivot<0){
            reverse(nums.begin(),nums.end());
        }
        
        else{
            for(int i=N-1;i>pivot;i--){
                if(nums[i]>nums[pivot]){
                    swap(nums[i],nums[pivot]);
                    break;
                }
                
            }
            reverse(nums.begin()+pivot+1,nums.end());
        }
        return nums;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends