class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
         vector<vector<int>> spiral( n , vector<int> (n, 0)); 
        int count=0;
        int startRow=0;
        int startCol=0;
        int endRow=n-1;
        int endCol=n-1;
        int total = n*n;
        while(count<total){
            for(int index=startCol;index<=endCol&&count<total;index++){
                count++;
                spiral[startRow][index]=count;
                
            }
            startRow++;
            for(int index=startRow;index<=endRow&&count<total;index++){
                count++;
                spiral[index][endCol]=count;
               
            }
            endCol--;
            for(int index=endCol;index>=startCol&&count<total;index--){
                count++;
                spiral[endRow][index]=count;
               
            }
            endRow--;
            for(int index=endRow;index>=startRow&&count<total;index--){
                count++;
                spiral[index][startCol]=count;
                
            }
            startCol++;
            
        }
        return spiral;
    }
};