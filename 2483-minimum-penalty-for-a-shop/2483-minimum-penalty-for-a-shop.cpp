class Solution {
public:
    int bestClosingTime(string customers) {
        int len=customers.length();
        int yCount=0;
        int nCount=0;
        vector<int> ans(len+1,0);
        for(int i=0;i<len;i++){
            if(customers[i]=='Y'){
                yCount++;
            }
            
        }
        int i;
        
        for( i=0;i<len;i++){
            ans[i]=yCount+nCount;
            if(customers[i]=='Y'){
                yCount--;
            }
            else nCount++;
        }
         ans[i]=yCount+nCount;
        int mini=INT_MAX;
        int index;
        for(int i=0;i<=len;i++){
           if(ans[i]<mini){
               mini=min(mini,ans[i]);
           }
        }
        for(int i=0;i<=len;i++){
           if(ans[i]==mini){
               index=i;
               break;
           }
           
        }
        return index;
    }
};