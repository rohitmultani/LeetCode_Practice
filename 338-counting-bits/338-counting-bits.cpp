class Solution {
public:
    int count(int i){
    int cal = 0;
    while(i!=0){
        if(i&1)
            cal++;
        i=i>>1;
    }
    return cal;
}
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i = 0 ; i<=n ; i++){
            ans.push_back(count(i));
        }
        return ans;
    }
};
