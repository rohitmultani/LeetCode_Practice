class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size();
        int col=matrix[0].size();
       
        
        int s=0;
        int e=row*col-1;
        int mid = s + (e-s)/2;
    
        while(s<=e){
            int element = matrix[mid/col][mid%col];
            
            if(element==target)
                return true;
            else if (element>target){
                cout<<e;
                e=mid-1;
                
            }
            else if(element<target){
                cout<<s;
                s=mid+1;
                
            }
            mid = s + (e-s)/2;
        }
        return 0;
    }
};