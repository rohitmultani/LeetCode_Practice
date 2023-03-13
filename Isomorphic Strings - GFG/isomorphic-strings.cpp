//{ Driver Code Starts
// C++ program to check if two strings are isomorphic


#include<bits/stdc++.h>


using namespace std;
#define MAX_CHARS 256

// } Driver Code Ends
class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {
        unordered_map <char,char> mp, mp1;
        int len = str1.length();
        int len2 = str2.length();
        
        if(len != len2)
        return false;
        
        for(int i=0;i<len;i++){
            if(mp[str1[i]]!=str2[i] && mp[str1[i]])
            return false;
            if(mp1[str2[i]]!=str1[i] && mp1[str2[i]])
            return false;
            
            mp[str1[i]]=str2[i];
            mp1[str2[i]]=str1[i];
        }
        return true;
    }
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}
// } Driver Code Ends