class Solution {
public:
    bool checkIfPangram(string sentence) {
      int check[26]={0};
        for(int i=0;i<sentence.length();i++){
            int index = sentence[i]-'a';
            check[index]++;
        }
        for(int i=0;i<26;i++){
            if(check[i]==0)
                return false;
        }
        return true;
    }
};