//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
      map<int,int> mp;
        if(N==0)
        return 0;
        
        for(int i=0;i<N;i++){
            mp[arr[i]]=arr[i]+1;
        }
        int len=1;
        int ans=1;
        
        for(auto i:mp){
            if(mp.find(i.second)!=mp.end()){
                
                len++;
                ans=max(len,ans);
            }
            else{
                len=1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends