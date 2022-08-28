class Solution {
public:
    string reverse(string s, int i, int j){
        string ans = "";
        int start=i;
        int end=j-1;
            
        while(start<=end){
            ans.push_back(s[end--]);
            
        }
        return ans;
    }
    string reverseWords(string s) {
        string ans="";
        int i=0;
        for(int j=0;j<s.length();j++){
            if(s[i]==' '){
                i++;
                if(i>=s.length())
                    ans.pop_back();
            }
            else if(s[j]==' '){
                ans = ans + reverse(s,i,j);
                ans=ans + " ";
                i=j+1;
            }
            else if((j==s.length()-1) && (s[j]!=' ')){
                 ans = ans + reverse(s,i,j+1);
             s = reverse(s,i,j+1);
            }
        }
     
        return reverse(ans,0,ans.length());
     
    }
};