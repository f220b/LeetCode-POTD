// Last updated: 4/3/2026, 1:48:29 PM
class Solution {
public:
    int n;
    int maxLen;
    int expand(string& s, int left, int right, bool skipped) {
        while (left >= 0 && right < n) {
            if (s[left] == s[right]) {
                left--;
                right++;
            } else if (!skipped) {
                int skipLeft = expand(s, left - 1, right, true);
                int skipRight = expand(s, left, right + 1, true);
                return max(skipLeft, skipRight);
            } else
                break;
        }
        int currLen = right - left - 1;
        if (!skipped && currLen < n)
            return currLen + 1;
        return currLen;
    }
    int almostPalindromic(string s) {
        n = s.length();
        maxLen = 0;

        for (int i = 0; i < n; i++) {
            maxLen = max(maxLen, expand(s, i, i, false));
            maxLen = max(maxLen, expand(s, i, i + 1, false));
        }
        return maxLen;
    }
};