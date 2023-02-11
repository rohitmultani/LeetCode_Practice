//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        int rowStart=0;
        int colStart=0;
        int rowEnd=r-1;
        int colEnd=c-1;
        vector<int> ans;
        while(rowStart<rowEnd && colStart<colEnd){
            
            //left to right
            for(int i=colStart;i<=colEnd;i++){
                ans.push_back(matrix[rowStart][i]);
            }
            rowStart++;
            
            //top to bottom
            for(int i=rowStart;i<=rowEnd;i++){
                ans.push_back(matrix[i][colEnd]);
            }
            colEnd--;
            
            //right to left
            for(int i=colEnd;i>=colStart;i--){
                ans.push_back(matrix[rowEnd][i]);
            }
            rowEnd--;
            
            //bottom to top
            for(int i=rowEnd;i>=rowStart;i--){
                ans.push_back(matrix[i][colStart]);
            }
            colStart++;
            
        }
        
        if(rowStart==rowEnd){
             for(int i=colStart;i<=colEnd;i++){
                ans.push_back(matrix[rowStart][i]);
            }
        }
        else if(colStart==colEnd){
             for(int i=rowStart;i<=rowEnd;i++){
                ans.push_back(matrix[i][colEnd]);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends