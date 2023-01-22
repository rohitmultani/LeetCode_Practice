class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int i=0;
        int j=0;
        int s1=nums1.size();
        int s2=nums2.size();
        if(nums1[s1-1]>=nums2[0]){
        while(i<s1 || j<s2){
            cout<<"hello";
            if(nums1[i]==nums2[j])
                return nums1[i];
            else if(nums1[i]<nums2[j])
                i++;
            else j++;
        }
        }
        
        return -1;
    }
};