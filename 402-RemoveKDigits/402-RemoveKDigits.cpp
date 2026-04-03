// Last updated: 4/3/2026, 2:00:19 PM

class Solution {
public:
    string removeKdigits(string num, int k) {
        if (k == num.length())
            return "0"; // Directly return "0" if all digits are removed

        stack<char> st;
        for (char digit : num) {
            while (!st.empty() && k > 0 && st.top() > digit) {
                st.pop();
                k--;
            }
            st.push(digit);
        }

        // Remove remaining digits if `k > 0`
        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

        // Build the result string
        string result;
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        reverse(result.begin(), result.end());

        // Remove leading zeros manually
        int i = 0;
        while (i < result.size() && result[i] == '0') {
            i++;
        }

        return i == result.size() ? "0" : result.substr(i);
    }
};
