class Solution {
public:
    int pivotInteger(int n) {
        int rSum=0;
        int lSum=0;
        int sum=0;
        for(int i=1;i<=n;i++){
            sum=sum+i;
        }
        int pivot;
        bool flag=false;
        for(int i=1;i<=n;i++){
            lSum=lSum+i;
            rSum=sum;
            if(lSum==rSum){
                pivot=i;
                flag=true;
                break;
            }
                
            
            sum=sum-i;
        }
        if(flag){
            return pivot;
        }
        else return -1;
            
    }
};