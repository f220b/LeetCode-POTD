// Last updated: 9/5/2026, 12:09:32 AM
class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        s = "1" + s + "1";

        int n = s.size();
        int totalOnes = -2; // ignore the two added boundary 1's

        int i = 0;
        int lastZero = 0, one = 0, currZero = 0;
        int ans = 0;

        while (i < n) {
            char ch = s[i];
            int len = 0;
            while (i < n && s[i] == ch) {
                len++;
                i++;
            }

            if (ch == '1') {
                totalOnes += len;
                one = len;
            } else {
                currZero = len;

                if (lastZero > 0 && one > 0) {
                    ans = max(ans, lastZero + currZero);
                }

                lastZero = currZero;
                one = 0;
            }
        }

        return totalOnes + ans;
    }
};
