class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int len = 0;
        st.push(-1);
        for(int i=0; i<s.length(); i++){
            if(s[i] == '(') {
                st.push(i);
            }
            else {
                st.pop(); 
                if(st.empty())                
                    st.push(i);
                else
                    len = max(len,i-st.top());
            }
            
        }
        return len;
    }
};