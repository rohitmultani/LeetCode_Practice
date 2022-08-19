class Solution {
public:
    int first(vector<int>& arr, int n, int key){
    int s=0,e=n-1;
    int mid = s + (e-s)/2;
//     cout<<arr[mid];
    int ans=-1;
    while(s<=e){
        if(arr[mid]==key){
            ans=mid;
            e=mid-1;
        }
        else if(key>arr[mid]){
            s=mid+1;
        }
        else if(key<arr[mid]){
            e=mid-1;
        }
        mid = s + (e-s)/2;
    }
        return ans;
}
int last(vector<int>& arr, int n, int key){
    int s=0,e=n-1;
    int mid = s + (e-s)/2;
    int ans=-1;
    while(s<=e){
        if(arr[mid]==key){
            ans=mid;
            s=mid+1;
        }
        else if(key>arr[mid]){
            s=mid+1;
        }
        else if(key<arr[mid]){
            e=mid-1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        ans.push_back(first(nums,nums.size(),target));
        ans.push_back(last(nums,nums.size(),target));
        return ans;
    }
};