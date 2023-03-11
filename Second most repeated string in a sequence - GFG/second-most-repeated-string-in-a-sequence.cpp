//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
  public:
    string secFrequent (string arr[], int n)
    {
       map<string,int> mp;
        int maxCount = 0;
        int sHighest = 0;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
            maxCount = max(maxCount,mp[arr[i]]);
        }
        if(mp.size()==1)
        return "";
        for(auto i:mp){
           if(sHighest<i.second && i.second <maxCount){
               sHighest = i.second;
           }
        }
        for(auto i:mp){
            if(i.second == sHighest){
                return i.first;
            }
        }
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        Solution ob;
        cout << ob.secFrequent (arr, n) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends