//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    
	public:
	
	    void solve(string S,vector<string> &ans,int index){
	        if(index>=S.length()){
	            if(find(ans.begin(), ans.end(), S) == ans.end())
	            ans.push_back(S);
	            return;
	        }
	        
	        for(int j=index;j<S.length();j++){
	            swap(S[index],S[j]);
	             solve(S,ans, index+1);
	             
	              swap(S[index],S[j]);
	        }
	    }
		vector<string>find_permutation(string S)
		{
		    vector<string> ans;
		    int index=0;
		    solve(S,ans, index);
		    sort(ans.begin(),ans.end());
		    return ans;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends