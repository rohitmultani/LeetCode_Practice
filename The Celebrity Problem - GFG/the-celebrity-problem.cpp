//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
#include<stack>
class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int> celeb;
        for(int i=0;i<n;i++){
            celeb.push(i);
        }
        while(celeb.size()>1){
            //pop two elements;
            int a=celeb.top();
            celeb.pop();
            int b=celeb.top();
            celeb.pop();
            if(M[a][b])
            celeb.push(b);
            else if(M[b][a])
            celeb.push(a);
        }
        int ans=celeb.top();
        for(int i=0;i<n;i++){
            if((M[ans][i]==1 || M[i][ans]==0 )&&i!=ans)
            return -1;
            
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
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends