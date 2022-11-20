class Solution {
public:
    int unequalTriplets(vector<int>& nums) {
        int len=nums.size();
        int count = 0;
        for(int i=0;i<len;i++){
            for(int j=i+1;j<len;j++){
                for(int k=j+1;k<len;k++){
                    if(nums[i]!=nums[j] && nums[j]!=nums[k] && nums[i]!=nums[k]){
                        count++;
                    }
                }
            }
        }
        return count;
    }
};