//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int minimumCostOfBreaking(vector<int> X, vector<int> Y, int M, int N){
        sort(X.begin(),X.end(),greater<int>());
        sort(Y.begin(),Y.end(),greater<int>());
        
        
        int ans = 0 ;
        int i=0;
        int j=0;
        int hCount=1;
        int vCount=1;
        M--;
        N--;
        while(i<M && j<N){
            if(X[i]>Y[j]){
                ans+=X[i]*vCount;
                hCount++;
                i++;
            }
            else{
                ans+=Y[j]*hCount;
                vCount++;
                j++;
            }
        }
        
        while(i<M){
                ans+=X[i]*vCount;
                i++;
                hCount++;
        }
        
        while(j<N){
                ans+=Y[j]*hCount;
                j++;
                vCount++;
        }
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
	    int m, n;
	    cin >> m >> n;
	    vector<int>X(m - 1), Y(n - 1);
	    for(int i = 0; i < m - 1; i++){
	        cin >> X[i];
	    }
	    for(int i = 0; i < n - 1; i++){
	        cin >> Y[i];
	    }
	    Solution ob;
	    int ans = ob.minimumCostOfBreaking(X, Y, m, n);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends