//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
   
    public:
     bool check(int mid, int n){
        int count = 0 ;
        for(int i=5;mid/i>=1;i*=5){
            count+=mid/i;
        }
        return count>=n;
    }
        int findNum(int n)
        {
        if(n==1)
        return 5;
        
        int low=0;
        int high=5*n;
        
        while(low<high){
            int mid = (low+high)>>1;
            if(check(mid,n))
            high=mid;
            else
            low=mid+1;
        }
        return low;
        }
};

//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Solution ob;
        cout <<ob.findNum(n) << endl;
    }
return 0;
}
// } Driver Code Ends