// Last updated: 4/3/2026, 2:01:43 PM
class Solution {
public:
    int titleToNumber(string columnTitle) {
        int res = 0;
        for (char c : columnTitle) {
            int d = c - 'A' + 1;
            res = res * 26 + d;
            // Just like base conversion
            // Binary to Decimal......multiply by 2
            // Hexadecimal to Decimal......multiply by 16
        }
        return res;
    }
};