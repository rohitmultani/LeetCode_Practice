//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maximumPath(int N, vector<vector<int>> matrix)
    {
    int n = matrix.size();
    int m = matrix[0].size();
    int maxi = -1e8;
    vector<vector<int>> dp(n,vector<int>(m,0));
    vector<int> prev(m,0),curr(m,0);
    for(int j=0;j<m;j++)
    prev[j]=matrix[0][j];

    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            int u = matrix[i][j] + prev[j];

            int ld = matrix[i][j];
            if(j-1>=0)
            ld+= prev[j-1];
            else ld = -1e8;


            int rd = matrix[i][j];
            if(j+1<m)
            rd+= prev[j+1];
            else
            rd = -1e8;

            curr[j] = max(u,max(ld,rd));
        }
        prev=curr;

    }




    for(int j=0;j<m;j++){
        maxi=max(maxi,prev[j]);
    }
    return maxi;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends