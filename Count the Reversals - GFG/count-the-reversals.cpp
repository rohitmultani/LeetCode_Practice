//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends



int countRev (string s)
{
    stack<char> str;
    
    int len = s.length();
    if(len&1)
    return -1;
    int count = 0;
    for(int i=0;i<len;i++){
        if(str.empty()){
            if(s[i]=='}'){
            str.push('{');
            count++;    
            }
            else {
                str.push('{');
            }
        }
        else {
            if(s[i]=='}' && str.top()=='{'){
            str.pop();
            }
            else if(s[i]=='{') {
                str.push('{');
            }
        }
    }
    count += str.size()/2;
    return count;
}