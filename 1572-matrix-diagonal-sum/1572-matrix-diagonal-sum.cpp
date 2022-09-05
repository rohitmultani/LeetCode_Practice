class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int startRow=0;
        int startCol=0;
        int endRow=mat.size()-1;
        int endCol=mat.size()-1;
        int sum=0;
        while(startRow<endRow){
            sum+=mat[startRow][startCol];
            sum+=mat[startRow][endCol];
            sum+=mat[endRow][startCol];
            sum+=mat[endRow][endCol];
            startRow++;
            startCol++;
            endRow--;
            endCol--;
        }
        if(startRow==endRow){
            sum+=mat[startRow][startCol];
        }
        return sum;
    }
};