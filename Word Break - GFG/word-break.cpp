//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
    unordered_set<string> s;
    unordered_map<int,bool> mp;
    bool solve(int i,string str){
        if(i>=str.length()){
            return mp[i]=true;
        }
        
        if(mp.find(i)!=mp.end()){
            return mp[i];
        }
        
        string tmp="";
        for(int k=i;k<str.length();k++){
            tmp+=str[k];
            if(s.find(tmp)!=s.end() && solve(k+1,str)){
                return mp[k]=true;
            }
        }
        return mp[i]=false;
    }
    int wordBreak(string A, vector<string> &B) {
        for(auto i:B){
            s.insert(i);
        }
        return solve(0,A);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends