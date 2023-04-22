//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    bool static cmp2(pair<pair<int,int>,int> &a, pair<pair<int,int>,int> &b){
        return (a.second<b.second);
    }
    vector<int> maxMeetings(int n,vector<int> &S,vector<int> &F){
     vector<pair<pair<int,int>,int>> vc;
     vector<int> ans;
     for(int i=0;i<n;i++){
         pair<int,int> p = make_pair(S[i],i+1);
         vc.push_back({p,F[i]});
     }
     
     sort(vc.begin(),vc.end(),cmp2);
     
     int count=1;
     int j=0;
     ans.push_back(vc[0].first.second);
     for(int i=1;i<n;i++){
         if(vc[i].first.first>vc[j].second)
         {
             count++;
             j=i;
             ans.push_back(vc[i].first.second);
         }
     }
     sort(ans.begin(),ans.end());
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
        vector<int> S(n),F(n);
        for(int i=0;i<n;i++){
            cin>>S[i];
        }
        for(int i=0;i<n;i++){
            cin>>F[i];
        }
        Solution ob;
        vector<int> ans=ob.maxMeetings(n,S,F);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i];
            if(i!=ans.size()-1){
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends