//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:

    bool static cmp(pair<int,int> a,pair<int,int> b){
        return a.second < b.second;
    }
    int buyMaximumProducts(int n, int k, int price[]){
        vector<pair<int,int>> vp;
        
        for(int i=0;i<n;i++){
            vp.push_back({i+1,price[i]});
        }
        
        sort(vp.begin(),vp.end(),cmp);
        int score = 0;
        int count = 0;
        for(int i=0;i<n;i++){
            int x;
            x = k/vp[i].second;
            
            if(x>vp[i].first){
                k = k - vp[i].first * vp[i].second;
                count+=vp[i].first;
            }
            else{
                k = k - x * vp[i].second;
                count+=x;
            }
            
            
        }
        
        return count;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n, k;
	    cin >> n >> k;
	    int price[n];
	    for(int i = 0 ; i < n; i++){
	        cin >> price[i];
	    }
	    Solution ob;
	    int ans = ob.buyMaximumProducts(n, k, price);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends