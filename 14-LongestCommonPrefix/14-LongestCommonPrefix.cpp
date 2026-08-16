// Last updated: 8/16/2026, 7:04:18 PM
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        int i = 0, n = strs.size();

        while (i < strs[0].length() && i < strs[n - 1].length() &&
               strs[0][i] == strs[n - 1][i])
            i++;
        
        return strs[0].substr(0, i);
    }
};