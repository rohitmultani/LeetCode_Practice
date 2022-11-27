class Solution {
public:
    int appendCharacters(string s, string t) {
        int len1=s.length();
        int len2=t.length();
        int i=0,j=0;
        while(i<len1 && j<len2){
            if(s[i]==t[j]){
                i++;
                j++;
            }
            else i++;
        }
        if(i<len1){
            return 0;
        }
        else return len2-j;
    }
};