class Solution {
public:
    bool matches(char top,char ch){
        if(top=='('&&ch==')' || top=='{'&&ch=='}' || top=='['&&ch==']')
            return true;
        else return false;
    }
    bool isValid(string s) {
        stack<char> b;
        for(int i=0;i<s.length();i++){
            char ch = s[i];
            //pushing opening bracket
            if(ch=='{'||ch=='['||ch=='('){
                b.push(ch);
            }
            else{
              if(!b.empty()){
                char top =b.top();
                if(matches(top,ch)){
                 b.pop();
                  }
                  else{
                      return false;
                  }
            }
           else return false;                
            }
        }
        if(b.empty())
            return true;
        else return false;
    }
};