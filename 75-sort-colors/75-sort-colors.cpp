class Solution {
public:
    void sortColors(vector<int>& nums) {
        int index=0;
        for(int i=0;i<=1&&index<nums.size();i++){
    
            for(int j=index+1;j<nums.size() && index<nums.size();j++){
                 if(nums[index]==i)
                index++;
                else if(nums[j]==i){
                    
                swap(nums[j],nums[index]);
                    index++;
                }

                
            }
        }
    }
};