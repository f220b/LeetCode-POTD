// Last updated: 4/3/2026, 1:49:05 PM
class Solution {
public:
    bool isBalanced(vector<int>& freq) {
        int common = 0;
        for (int f : freq) {
            if (f == 0)
                continue;
            if (common == 0)
                common = f;
            if (f != common)
                return false;
        }
        return true;
    }
    int longestBalanced(string s) {
        int maxLen = 0;
        vector<int> freq;
        for (int i = 0; i < s.length(); i++) {
            freq.assign(26, 0);
            for (int j = i; j < s.length(); j++) {
                freq[s[j] - 'a']++;
                if (isBalanced(freq))
                    maxLen = max(maxLen, j - i + 1);
            }
        }
        return maxLen;
    }
};