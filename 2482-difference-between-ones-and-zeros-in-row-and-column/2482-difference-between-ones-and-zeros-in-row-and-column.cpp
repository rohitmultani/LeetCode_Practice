class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
       
        vector<int> rowOne;
        vector<int> rowZero;
        vector<int> colOne;
        vector<int> colZero;
        int m=grid.size();
        int n=grid[0].size();
        
        vector<vector<int>> ans(m,vector<int> (n,0));
        for(int i=0;i<m;i++){
            int oneCount=0;
            int zeroCount=0;
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    zeroCount++;
                }
                else{
                    oneCount++;
                }
            }
            
            rowOne.push_back(oneCount);
            rowZero.push_back(zeroCount);
        }
        
        
         for(int i=0;i<n;i++){
            int oneCount=0;
            int zeroCount=0;
            for(int j=0;j<m;j++){
                if(grid[j][i]==0){
                    zeroCount++;
                }
                else{
                    oneCount++;
                }
            }
              
            colOne.push_back(oneCount);
            colZero.push_back(zeroCount);
        }
        
        for(int i=0;i<m;i++){
            
            for(int j=0;j<n;j++){
                ans[i][j]=rowOne[i] + colOne[j] - colZero[j] - rowZero[i];
            }
           
        }
        
        
        return ans;
        
    }
};