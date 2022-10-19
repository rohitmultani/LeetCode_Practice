class Solution {
public:
    int reverse(int x) {
        int rem=0;
        int temp=x;
        while(temp){
            // if(INT_MIN<(rem*10+temp%10)<INT_MAX){
            if((rem>INT_MAX/10)||(rem==INT_MAX/10 && temp%10>7))
                return 0;
             if (rem < INT_MIN/10 || (rem == INT_MIN / 10 && temp%10 < -8)) return 0;
            
            rem=rem*10+temp%10;
            temp=temp/10;
            }
        return rem;
    }
};