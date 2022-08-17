class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp,count;
        
        int ans = 0;
        for(auto i:arr){
            mp[i]++;
        }
    for(auto m:mp){
        if(++count[m.second]>1)
            return false;
        
    }
        return true;
    }
};