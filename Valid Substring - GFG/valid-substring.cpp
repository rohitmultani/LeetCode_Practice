//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for c++
class Solution {
  public:
    int findMaxLen(string str) {
        stack<int> s;
        int res=str.length();
        int maxCount=0;
                for(int i=0;i<str.length();i++){
                char ch=str[i];
                if(ch=='(')
                    s.push(i);
                else{
                    if(!s.empty()&&str[s.top()]=='(')
                        s.pop();
                    else{
                        s.push(i);
                    }
                }
            }
            
       
        while(!s.empty()){
            maxCount = max(maxCount,res - s.top() - 1);
            res=s.top();
            s.pop();
        }
        
        return max(maxCount,res);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S; 
        Solution ob;
        cout << ob.findMaxLen(S) << endl;
    }
    return 0;
}

// } Driver Code Ends