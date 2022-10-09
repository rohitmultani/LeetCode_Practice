class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map <int,int> major;
        for(int i=0;i<nums.size();i++){
            major[nums[i]]++;
        }
        int limit = nums.size()/2 + 1;
        for(auto i:major){
            if(i.second>=limit)
                return i.first;
        }
        return 0;
    }
};