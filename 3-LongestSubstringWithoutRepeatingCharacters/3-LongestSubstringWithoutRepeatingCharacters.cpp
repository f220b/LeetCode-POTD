// Last updated: 4/3/2026, 2:04:44 PM
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        
        vector<int> characters(256, -1);
        int left = 0, right = 0;
        int n = s.length();
        int maxLen = 0;

        while (right < n) {
            if (characters[s[right]] != -1) {
                left = max(left, characters[s[right]] + 1);
            }
            characters[s[right]] = right;
            maxLen = max(maxLen, right - left + 1);
            right++;
        }
        return maxLen;
    }
};