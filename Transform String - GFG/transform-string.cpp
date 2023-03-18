//{ Driver Code Starts
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    int transform (string A, string B)
    {
        int n1 = A.length();
        int n2 = B.length();
        if(n1!=n2)
        return -1;
       
       vector<int> freq(256,0);
       
       for(auto i:A){
           freq[i]++;
       }
       for(auto i:B){
           freq[i]--;
       }
       for(int i=0;i<256;i++){
           if(freq[i]!=0)
           return -1;
       }
       
        int count = 0;
        int i=n1-1,j=n2-1;
        while(i>=0 && j>=0){
            while(i>=0 && A[i]!=B[j]){
                i--;
                count++;
            }
            i--;
            j--;
        }
        
        return count;
       
        
    }
    
};


//{ Driver Code Starts.

int main () 
{
    int t; cin >> t;
    while (t--)
    {
        string A, B; 
        cin >> A >> B;
        Solution ob;
        cout <<ob.transform (A, B) << endl;
    }
}
// } Driver Code Ends