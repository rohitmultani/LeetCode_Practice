//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
public:
    int remove_duplicate(int a[],int n){
        int prev = 0;
        int curr = 1;
        int first = -1;
        int cnt = 1;
        
        while(curr<n){
            if(a[prev]!=a[curr]){
                cnt++;
                
                if(first!=-1){
                 a[first]=a[curr];
                first++;   
                }
                
                prev++;
                curr++;
                
            }
            else{
                a[curr]=-1;
                if(first==-1)
                first=curr;
                curr++;
            }
        }
        
        // for(int i=0;i<n;i++)
        // cout<<a[i]<<" ";
        return cnt;
        
    }
};

//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int a[N];
        for(int i=0;i<N;i++)
        {
            cin>>a[i];
        }
    Solution ob;
    int n = ob.remove_duplicate(a,N);

    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    }
}
// } Driver Code Ends