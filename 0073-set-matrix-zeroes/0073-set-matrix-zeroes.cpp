class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        
        vector<vector<int> > demo(row,vector<int> (col,0));
        //duplicate created;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                demo[i][j]=matrix[i][j];
            }
        }
        
        //traversing row
         for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j]==0){
                    for(int k=0;k<col;k++){
                        demo[i][k]=0;
                    }
                    for(int k=0;k<row;k++){
                        demo[k][j]=0;
                    }
                }
            }
        }
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                matrix[i][j]=demo[i][j];
            }
        }
    }
};