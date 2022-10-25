class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int len1,len2;
        len1=word1.size();
        len2=word2.size();
        string a="";
        string b="";
        for(int i=0;i<len1;i++){
           a=a+word1[i];
        }
        for(int i=0;i<len2;i++){
           b=b+word2[i];
        }
       
        return a==b;
    }
};