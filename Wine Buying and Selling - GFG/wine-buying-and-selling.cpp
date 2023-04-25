//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++


class Solution{
  public:
  long long int wineSelling(vector<int>& Arr, int N){
      int buy=0,sell=0;
      long long int ans = 0;
      while(buy<N && sell<N){
          while(Arr[buy]<=0){
              buy++;
              if(buy==N) return ans;
          }
          while(Arr[sell]>=0){
              sell++;
              if(sell==N) return ans;
          }
          if(abs(Arr[buy])>=abs(Arr[sell])){
              ans+=abs(buy-sell) * (abs(Arr[sell]));
              Arr[buy]+=Arr[sell];
              Arr[sell]=0;
          }
          else{
              ans+=abs(buy-sell) * Arr[buy];
              Arr[sell]+=Arr[buy];
              Arr[buy]=0;
          }
      }
      return ans;
  }
};



//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        long long int ans = ob.wineSelling(arr,n);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends