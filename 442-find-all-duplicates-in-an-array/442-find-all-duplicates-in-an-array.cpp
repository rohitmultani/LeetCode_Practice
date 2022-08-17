class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> duplicate;
        unordered_map<int,int> mp;
        for(auto i:nums)
            mp[i]++;
        for(auto m:mp)
        {
            if(m.second==2)
                duplicate.push_back(m.first);
        }
        return duplicate;
    }
};