// Last updated: 9/5/2026, 12:27:22 AM
class Solution {
public:
    bool checkOnesSegment(string s) {
        for (int i = 1; i < s.length(); i++) {
            if (s[i - 1] == '0' && s[i] == '1') {
                return false;
            }
        }
        return true;
    }
};