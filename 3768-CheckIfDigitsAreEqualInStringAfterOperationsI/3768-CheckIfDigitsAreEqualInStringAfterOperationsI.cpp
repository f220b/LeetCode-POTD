// Last updated: 4/3/2026, 1:50:05 PM
class Solution {
public:
    bool hasSameDigits(string s) {
        while (s.length() > 2) {
            string str = "";
            for (int i = 0; i < s.length() - 1; i++) {
                int d1 = s[i] - '0';
                int d2 = s[i + 1] - '0';
                int sum = (d1 + d2) % 10;
                str += (sum + '0');
            }
            s = str;
        }
        return s[0] == s[1];
    }
};