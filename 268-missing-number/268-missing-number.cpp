class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sumExpected = 0;
        int sumObt = 0;
        for(int i=0;i<=nums.size();i++){
            sumExpected+=i;
            if(i==nums.size())
                break;
            sumObt+=nums[i];
        }
        return sumExpected - sumObt;
    }
};