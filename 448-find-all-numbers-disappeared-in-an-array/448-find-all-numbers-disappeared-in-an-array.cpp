class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_map<int, int> nm;
        vector<int> ans;     
     for(int i=1;i<=nums.size();i++){
         nm[i]++;
     }
         for(auto i:nums){
            nm[i]++;
        }
        for(auto i:nm){
            if(i.second==1){
                ans.push_back(i.first);
            }
        }
        
        return ans;
        
    }
};