class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int s = 0; 
        int e = nums.size()-1;
        int mid  = s + (e-s)/2;
        int found=0;
        while(s<=e){
            if(target==nums[mid]){
                found = 1;
                return mid;
            }
            else if(target>nums[mid]){
                s=mid+1;
                if(s>e){
                    return s;
                }
            }
            else if(target<nums[mid]){
                e=mid-1;
            }
            if(s>e){
                return s;
            }
            mid  = s + (e-s)/2;
        }
        return 0;
    }
};