class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        map<int,int> n;
        int ans=-1;
        int max=0;
        for(int i=0;i<nums.size();i++){
            n[nums[i]]++;
        }
        for(auto i:n){
            if(i.first%2==0 && i.second>max){
                max=i.second;
                ans=i.first;
            }
           
        }
        return ans;
    }
};