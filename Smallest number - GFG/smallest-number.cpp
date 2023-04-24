//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    string smallestNumber(int S, int D){
        if(S==0){
            if(D>1)
            return "-1";
            
            if(D==0)
            return "0";
        }
        
        if(S > 9*D)
        return "-1";
        
        S=S-1;
        
        string ans;
        
        for(int i=D-1;i>0;i--){
            if(S>9){
            ans.push_back('9');
            S=S-9;
            }
            else{
                ans.push_back(char(S) + '0');
                S=0;
            }
        }
        
        ans.push_back(char(S+1)+'0');
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int S,D;
        cin >> S >> D;
        Solution ob;
        cout << ob.smallestNumber(S,D) << endl;
    }
    return 0; 
} 
// } Driver Code Ends