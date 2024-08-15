class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        // char ca[] = s.c_str();
        for(int i=0; i<s.length(); i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
                st.push(s[i]);
            else{
                if(st.empty())
                    return false;
                if((s[i]==')' && st.top() == '(') || (s[i]=='}' && st.top()=='{') || (s[i]==']' && st.top()=='['))
                    st.pop();
                else
                    return false;
            }
        }
        if(st.empty())
            return true;
        else 
            return false;
    }
};