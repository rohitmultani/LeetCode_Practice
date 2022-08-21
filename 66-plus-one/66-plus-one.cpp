#include<vector>
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        if(digits[n-1]<9){
            digits[n-1]++;
        }
        else if(digits[n-1]==9 && n>1){
            digits.pop_back();
            plusOne(digits);
            digits.push_back(0);
            
        }
        else if(digits[n-1]==9 && n==1){            
            digits.clear();
            digits.push_back(1);
            digits.push_back(0);
        }
        return digits;
    }
};