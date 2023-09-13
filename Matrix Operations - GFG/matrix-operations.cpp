//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    pair<int,int> endPoints(vector<vector<int>> matrix){
        int i=0,j=0;
        int pI=0,pJ=0;
        char currD = 'r';
        int R = matrix.size();
        int C = matrix[0].size();
         map<char,char> rcd = {{'l', 'u'},{'u', 'r'},
                        {'r', 'd'},
                        {'d', 'l'}};
        
        
        
        while(i>=0 && i<R && j>=0 && j<C){
            // cout<<i<<" "<<j<<endl;
            pI = i;
            pJ = j;
            
            if(matrix[i][j]==1){
                char move = rcd[currD];
                matrix[i][j]=0;
                
                if(move=='u')
                i-=1;
                else if(move=='d')
                i+=1;
                else if(move=='l')
                j-=1;
                else if(move=='r')
                j+=1;
                
                currD = move;
            }
            else{
                if (currD == 'u')
        i -= 1;
      else if(currD == 'd')
        i += 1;
      else if(currD == 'l')
        j -= 1;
      else if(currD == 'r')
        j += 1;
            }

        }
         return {pI,pJ};
    }

};

//{ Driver Code Starts.


int main()
{
    int tc;
	scanf("%d", &tc);
	while(tc--){
		int row, col;
		scanf("%d", &row);
		scanf("%d", &col);
		vector<vector<int>> matrix(row , vector<int> (col));
	 
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
			    cin>>matrix[i][j];
			}
		}
		Solution obj;
		pair<int,int> p = obj.endPoints(matrix);
		
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}
	return 0;
}
// } Driver Code Ends