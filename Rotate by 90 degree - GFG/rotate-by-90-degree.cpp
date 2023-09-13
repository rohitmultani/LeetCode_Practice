//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;
void rotate (vector<vector<int> >& matrix);


// } Driver Code Ends
//User function template for C++

/* matrix : given input matrix, you are require 
 to change it in place without using extra space */
void rotate(vector<vector<int> >& matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    
    for(int i=0;i<m;i++){
        for(int j=i;j<n;j++){
            if(i==j)
            continue;
            
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    
    
    for(int j=0;j<n;j++){
        for(int i=0;i<m/2;i++){
            swap(matrix[i][j],matrix[m-i-1][j]);
            
        }
            
    }
}


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t; 
    while(t--)
    {
        int n;
        cin>>n; 
        vector<vector<int> > matrix(n);
        for(int i=0; i<n; i++)
        {
            matrix[i].resize(n);
            for(int j=0; j<n; j++)
                cin>>matrix[i][j]; 
        }
        rotate(matrix);
        for (int i = 0; i < n; ++i)
        {
            for(int j=0; j<n; j++)
                cout<<matrix[i][j]<<" ";
            cout<<"\n";
        }
    }
    return 0;
}


// } Driver Code Ends