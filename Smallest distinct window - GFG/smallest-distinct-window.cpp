//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int findSubString(string s)
    {
       int n = s.length();
       unordered_map<char,int> m;
       for(int i=0;i<n;i++){
           m[s[i]]++;
       }
       int dis = m.size();
       int head = -1,tail=0,cn=0,ans=n;
       m.clear();
       
       while(tail<n){
           while(head+1<n && cn<dis){
               m[s[++head]]++;
               if(m[s[head]]==1){
                   cn++;
               }
           }
           if(cn==dis){
               ans = min(ans,head-tail+1);
           }
           if(head>=tail){
               m[s[tail]]--;
               if(m[s[tail]]==0){
                   cn--;
               }
               tail++;
               if(cn==dis){
                   ans = min(ans,head-tail+1);
               }
           }
       }
       return ans;
    }
};

//{ Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}
// } Driver Code Ends