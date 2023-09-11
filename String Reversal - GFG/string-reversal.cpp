//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
string reverseString(string s);
int main()
{
	int t;
	cin>>t;
	cin.ignore();
	while(t--)
	    {
	        string s;
	        getline(cin,s);
	        cout<<reverseString(s)<<endl;
	    }
}

// } Driver Code Ends


string reverseString(string s)
{
    unordered_map<char,int> mp;
    string ans="";
    
    
    for(int i=s.length();i>=0;i--){
               if(mp[s[i]]==0 && s[i]!=' '){
                ans+=s[i];
                mp[s[i]]++;
               }
        }
    
    
    return ans;
    
}