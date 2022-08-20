class Solution {
public:
    bool isPossible(vector<int> arr, int days,int mid){
    int Count=1;
    int Sum = 0;
    for(int i=0;i<arr.size();i++){
        if(Sum+arr[i]<=mid){
            Sum+=arr[i];
        }
        else{
            Count++;
            if(Count>days || arr[i]>mid){
                return false;
            }
            Sum=arr[i];
        }
    }
    return true;
}
    int shipWithinDays(vector<int>& weights, int days) {
     int s=0;
    int sum=0;
    for(int i=0;i<weights.size();i++){
        sum+=weights[i];
    }
    int e=sum;
    int ans=-1;
    int mid = s + (e-s)/2;
    while(s<=e){
        if(isPossible(weights,days,mid)){
            ans=mid;
            e=mid-1;
        }
        else{
            s=mid+1;
        }
        mid = s + (e-s)/2;
    }
    return ans;

    }
};