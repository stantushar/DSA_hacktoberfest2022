class Solution {
public:
    bool isValid(string s) {
        stack <char> str;
        int len=s.length();
        for(int i=0;i<len;i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
                str.push(s[i]);
            else if(s[i]==')' || s[i]=='}' || s[i]==']'){
                if(str.empty())
                    return false;
                else if(s[i]==')' && str.top()!='(')
                    return false;
                else if(s[i]=='}' && str.top()!='{')
                    return false;
                else if(s[i]==']' && str.top()!='[')
                    return false;
                else
                    str.pop();
            }
        }
        if(str.empty())
            return true;
        else 
            return false;
    }
};
