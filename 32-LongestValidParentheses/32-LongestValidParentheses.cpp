// Last updated: 4/3/2026, 2:04:08 PM
class Solution {
public:
    int longestValidParentheses(string s) {
        int left = 0, right = 0, maxLen = 0;

        for (char ch : s) {
            if (ch == '(') {
                left++;
            } else {
                right++;
            }

            if (left == right) {
                maxLen = max(maxLen, 2 * left);
            } else if (right > left) {
                left = 0;
                right = 0;
            }
        }
        left = 0;
        right = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] == ')') {
                right++;
            } else {
                left++;
            }

            if (left == right) {
                maxLen = max(maxLen, 2 * right);
            } else if (left > right) {
                left = 0;
                right = 0;
            }
        }
        return maxLen;
    }
};