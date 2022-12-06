class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int rowStart=0;
        int colStart=0;
        int rowEnd=n-1;
        int colEnd=n-1;
        while(rowStart<rowEnd){
            
        
        int i=0;
            //rowEnd-rowStart i pointer how many times does internally it have to iterate
        while(i<rowEnd-rowStart){
           
            //top right swap bottom right
            
            swap(matrix[rowStart+i][colEnd],matrix[rowEnd][colEnd-i]);
            //top left swap top right
            swap(matrix[rowStart][colStart+i],matrix[rowStart+i][colEnd]);
            //top left swap bottom left
            swap(matrix[rowEnd-i][colStart],matrix[rowStart][colStart+i]);

            
          i++;
            
            
        }
            rowStart++;
            rowEnd--;
            colStart++;
            colEnd--;
        }
        // [[2,29,20,26,16,28],[12,27,9,25,13,21],[32,33,32,2,28,14],[13,14,32,27,22,26],[33,1,20,7,21,7],[4,24,1,6,32,34]]
    }
};