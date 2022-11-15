class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> merge(n+m,0);
        int i=0,j=0,k=0;
            while(i<n && j<m){
                if(nums1[i]<=nums2[j]){
                    merge[k]=nums1[i];
                    k++;
                    i++;
                }
                else if(nums1[i]>nums2[j]){
                    merge[k]=nums2[j];
                    k++;
                    j++;
                }
            }
            while(i<n){
                merge[k]=nums1[i];
                k++;
                i++;
            }
            while(j<m){
                merge[k]=nums2[j];
                k++;
                j++;
            }
        if((n+m)&1){
            return merge[(n+m)/2];
        }
        else return (double(merge[(n+m)/2-1]) + double(merge[(n+m)/2]))/2;
        
    }
};