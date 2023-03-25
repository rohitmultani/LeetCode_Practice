//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    bool isPos(int A[],int N, int M, int target){
        
        int student = 1;
        int sum = 0;
        
        for(int i = 0; i<N;i++){
            if(A[i]+sum<=target)
            sum=sum+A[i];
            
            else{
                student++;
                if(student > M || A[i] > target){
                    return false;
                }
                    sum = A[i];
            }
        }
        return true;
    }
    
    int findPages(int A[], int N, int M) 
    {
        if(M>N)
        return -1;
        
        int start = 0;
        int sum =  accumulate(A, A+N, sum);
       
        int end = sum;
        
        int mid = start + (end-start)/2;
        
        int ans = -1;
        while(start<=end){
            if(isPos(A,N,M,mid)){
                ans = mid;
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
            
            mid = start + (end-start)/2;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends