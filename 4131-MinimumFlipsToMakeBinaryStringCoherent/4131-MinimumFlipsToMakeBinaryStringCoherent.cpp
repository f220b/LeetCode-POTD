// Last updated: 10/5/2026, 10:19:04 am
class Solution {
public:
    int minFlips(string s) {
        int n = s.length();
        if (n < 3)
            return 0;

        int ones = 0, zeroes = 0;
        for (char ch : s) {
            if (ch == '1')
                ones++;
            else
                zeroes++;
        }
        if (ones == 0)
            return 0;

        int flips = 0;
        if (s[0] == '1' && s[n - 1] == '1')
            flips = ones - 2;
        else if (s[0] == '1' || s[n - 1] == '1')
            flips = ones;
        else
            flips = ones + 2;
        return min({zeroes, flips, ones - 1});
    }
};