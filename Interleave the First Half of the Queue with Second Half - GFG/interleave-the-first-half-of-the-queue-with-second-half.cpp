//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<int> rearrangeQueue(queue<int> &q){
        queue<int> dm;
        int cnt=q.size()/2;
        
        while(cnt--){
            int val=q.front();
            q.pop();
            dm.push(val);
        }
        
        vector<int> ans;
        
        while(!dm.empty() && !q.empty()){
            int val = dm.front();
            dm.pop();
            
            ans.push_back(val);
            
            int val1 = q.front();
            q.pop();
            
            ans.push_back(val1);
            
        }
        
        // if(!dm.empty())
        // ans.push_back(dm.front());
        
        // if(!q.empty())
        // ans.push_back(q.front());
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        queue<int> q;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            q.push(a);
        }
        Solution ob;
        vector<int> ans=ob.rearrangeQueue(q);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}
// } Driver Code Ends