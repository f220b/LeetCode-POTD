// Last updated: 9/5/2026, 12:02:32 AM
class Solution {
public:
    int firstMatchingIndex(string s) {
        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (s[i] == s[n - i - 1])
                return i;
        }
        return - 1;
    }
};