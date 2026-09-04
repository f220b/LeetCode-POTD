// Last updated: 9/5/2026, 12:17:19 AM
class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words,
                                         vector<int>& groups) {
        vector<string> result;
        for (int i = 0; i < groups.size(); i++) {
            if (i == 0 || groups[i] != groups[i - 1])
                result.push_back(words[i]);
        }
        return result;
    }
};