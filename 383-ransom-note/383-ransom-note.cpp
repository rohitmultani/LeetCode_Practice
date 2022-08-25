class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> rN;
        unordered_map<char, int> mZ;
        for(char i:magazine){
            mZ[i]++;
        }
        for(char i:ransomNote){
            rN[i]++;
            if(rN[i]>mZ[i])
                return false;
        }
        return true;
    }
};