class Solution {
public:
    int getPivot(vector<int>& nums){
        int s = 0;
        int e = nums.size() - 1;
        int mid = s + (e-s)/2;
        while(s<e){
            if(nums[mid]>=nums[0]){
                s = mid+1;
            }
            else e=mid;
            mid = s + (e-s)/2;
        }
        return s;
    }
    int binarySearch(vector<int>& nums, int s,int e,int target){
        int lower=s,upper=e;
        int mid=lower+(upper-lower)/2;
        while(lower<=upper){
        if(nums[mid]==target)
            return mid;
        else if(nums[mid]>target){
            upper=mid-1;
        }
        else if(nums[mid]<target){
            lower=mid+1;
        }
       mid=lower+(upper-lower)/2;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
       int pivot = getPivot(nums);
        int n = nums.size();
        if(target>=nums[pivot] && target<=nums[n-1]){
            return binarySearch(nums,pivot,n-1,target);
        }
        else
    return binarySearch(nums,0,pivot-1,target);
    }
};