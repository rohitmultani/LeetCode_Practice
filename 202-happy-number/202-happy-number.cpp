class Solution {
public:
    bool isHappy(int n) {
        int rem=0;
        int temp=0;
        if(n>=2&&n<=6){
            return false;
        }
        while(n){
            rem=n%10;
            temp=temp+rem*rem;
            n/=10;
        }
        if(temp==1){
            return true;
        }
        else{
           return isHappy(temp);
        }
        return false;
    }
};