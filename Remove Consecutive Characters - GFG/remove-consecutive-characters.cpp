//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
class Solution{
    public:
    string removeConsecutiveCharacter(string S)
    {
        int len = S.length();
        vector<char> ans;
        for(int i=0;i<len;i++){
            int size = ans.size();
            if(size>0){
                char c = ans[size-1];
                
                if(c==S[i])
                continue;
                else
                ans.push_back(S[i]);
            }
            else{
                 ans.push_back(S[i]);
            }
        }
        
        for(int i=0;i<ans.size();i++){
            S[i]=ans[i];
        }
    return S.substr(0,ans.size());
        
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.removeConsecutiveCharacter(s)<<endl;
    }
} 




// } Driver Code Ends