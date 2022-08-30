class Solution {
public:
    string removeDuplicates(string s) {
        int i=0;
        while((i<s.length()-1) && (s.length()!=0)){
            if(s[i]==s[i+1]){
                s.erase(s.begin()+i,s.begin()+i+2);
                if(i>0)
                    i--;
                else if(i==0){
                    i=0;
                }
                
            }
            else i++;
        }
        return s;
    }
};