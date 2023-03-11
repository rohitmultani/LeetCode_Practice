//{ Driver Code Starts
//Initial template for C++ 
 
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//User function template for C++

class Solution{
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
};

//{ Driver Code Starts.

int main() 
{
   

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string str;
   		cin >> str;

   		Solution ob;

   		cout << ob.lps(str) << "\n";
   	}

    return 0;
}

// } Driver Code Ends