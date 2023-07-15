//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	int lps(string s) {
	    vector<int> lps(s.length());
	    lps[0]=0;
	    int i=1;
	    int len = 0;
	    
	    while(i<s.length()){
	        if(s[i]==s[len]){
	            lps[i]=++len;
	            i++;
	        }
	        else{
	            if(len!=0){
	                len = lps[len-1];
	            }
	            else{
	                lps[i]=0;
	                i++;
	            }
	        }
	    }
	    return lps[s.length()-1];
	}
    int minChar(string str){
        string rev = str;
        reverse(rev.begin(),rev.end());
        string c = str + "#" + rev;
        return str.length()-lps(c);
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin >> str;
	    Solution ob;
	    int ans = ob.minChar(str);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends