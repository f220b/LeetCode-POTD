// Last updated: 4/3/2026, 2:04:19 PM
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char ch : s) {
            if (ch == '(')
                st.push(')');
            else if (ch == '{')
                st.push('}');
            else if (ch == '[')
                st.push(']');
            else if (st.empty() || st.top() != ch)
                return false;
            else
                st.pop();
        }
        return st.empty();
    }
};