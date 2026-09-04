// Last updated: 9/5/2026, 12:00:47 AM
class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int n = s.length(), m = t.length();
        if (n > m)
            return false;

        int match0 = 0, match1 = 0;

        for (char c : t) {
            int next0 = match0;
            int next1 = match1;

            if (match0 < n) {
                if (c == s[match0]) {
                    next0 = match0 + 1;
                }
                if (match0 + 1 > next1) {
                    next1 = match0 + 1;
                }
            }

            if (match1 < n && c == s[match1]) {
                if (match1 + 1 > next1) {
                    next1 = match1 + 1;
                }
            }

            match0 = next0;
            match1 = next1;

            if (match1 == n)
                return true;
        }

        return match1 == n;
    }
};