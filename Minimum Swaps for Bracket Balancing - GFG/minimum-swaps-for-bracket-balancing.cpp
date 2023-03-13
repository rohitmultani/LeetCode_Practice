//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    int minimumNumberOfSwaps(string S){
        int len = S.length();
        int left = 0;
        int right = 0;
        int imbal = 0;
        int swap = 0;
        
        for(int i=0;i<len;i++){
            if(S[i]=='['){
                left++;
                if(imbal>0){
                    swap+=imbal;
                    imbal--;
                }
            }
            else{
                right++;
                
                imbal=right-left;
            }
        }
        return swap;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.minimumNumberOfSwaps(S) << endl;
    }
    return 0; 
} 
// } Driver Code Ends