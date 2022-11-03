class Solution {
public:
    int countAsterisks(string s) {
        int len=s.length();
        stack<char> st;
        int open=1;
        for(int i=0;i<len;i++){
            char ch=s[i];
            
            if(ch=='|'&& open==1)
            {
                st.push(ch);
                
                open=0;
            }
            else if(ch!='|')
                st.push(ch);
            else if(ch=='|'&& open==0){
                open=1;
                
                while(st.top()!='|'){
                    st.pop();
                }
                st.pop();
            }
        }
        int count=0;
        while(!st.empty()){
            if(st.top()=='*'){
                count++;
                
            }
            st.pop();
        }
        return count;
        
    }
};