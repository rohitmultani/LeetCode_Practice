//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
vector<int> find(int arr[], int n , int x )
{
    int start =  0;
    int end = n;
    int mid = start + (end-start)/2;
    vector<int> ans;
    
    //1st pos
    int res = -1;
    while(start<=end){
       if(arr[mid]==x){
           res = mid;
           end = mid -1;
            
       }      
       else if(arr[mid]<x)
       start=mid+1;
       
       else end=mid-1;
       
       mid = start + (end-start)/2;
    }
   ans.push_back(res);
    res=-1;
    start = 0;
    end = n;
    mid = start + (end-start)/2;
     while(start<=end){
        if(arr[mid]==x){
            res = mid;
            start=mid+1;
            
       }      
       else if(arr[mid]<x)
       start=mid+1;
       else end=mid-1;
       mid = start + (end-start)/2;
    }
    ans.push_back(res);
    return ans;
}

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends