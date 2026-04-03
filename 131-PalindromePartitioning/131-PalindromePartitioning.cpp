// Last updated: 4/3/2026, 2:02:15 PM
class Solution {
public:
    bool checkPalindrome(string s, int start, int end) {
        while (start <= end) {
            if (s[start++] != s[end--])
                return false;
        }
        return true;
    }
    void findPartition(string s, int index, vector<vector<string>>& ans,
                       vector<string>& ds) {
        if (index == s.length()) {
            ans.push_back(ds);
            return;
        }
        for (int i = index; i < s.length(); i++) {
            if (checkPalindrome(s, index, i)) {
                ds.push_back(s.substr(index, i - index + 1));
                findPartition(s, i + 1, ans, ds);
                ds.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> ds;
        findPartition(s, 0, ans, ds);
        return ans;
    }
};