class Solution {
public:
    bool isAnagram(string s, string t) {
        int A[26]={0};
        for(int i=0;i<s.length();i++){
            char ch=s[i];
            int index=ch-'a';
            A[index]++;
        }
        
        for(int i=0;i<t.length();i++){
            char ch=t[i];
            int index=ch-'a';
            if(A[index]==0)
                return false;
            else
                A[index]--;
        }
        for(int i=0;i<26;i++){
           if(A[i]!=0)  
               return false;
        }
        return true;
    }
};