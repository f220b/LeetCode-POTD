// Last updated: 4/3/2026, 2:00:09 PM
class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0, right = 0;
        int maxLen = 0, maxCount = 0;
        int len = s.length();
        vector<int> count(26, 0);

        while (right < len) {
            count[s[right] - 'A']++;
            maxCount = max(maxCount, count[s[right] - 'A']);

            while (right - left + 1 - maxCount > k) {
                count[s[left] - 'A']--;
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
            right++;
        }
        return maxLen;
    }
};