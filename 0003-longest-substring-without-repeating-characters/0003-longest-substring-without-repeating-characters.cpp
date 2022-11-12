class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        if(len==0){
            return 0;
        }
        int subLen=1;
        int maxLen=1;
        int i=0,j=0;
        map<char,int> seen;
                while( i<=j && i<len && j<len){
                     seen[s[j]]=j;
                    if(seen.find(s[j+1])!=seen.end()){
                        
                    subLen=j-i+1;   
                    maxLen=max(maxLen,subLen);
                       
                        if(seen[s[j+1]]>=i)
                        i=seen[s[j+1]]+1;
                        
                        j++;                                        
                    }
                    else{
                    subLen=j-i+1;   
                    maxLen=max(maxLen,subLen);
                        j++;
                    }
                     
        }
        return maxLen;
    }
};