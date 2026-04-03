// Last updated: 4/3/2026, 1:53:41 PM
class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = (int)s.size();

        int zeroCount = 0;
        for (char ch : s) {
            if (ch == '0')
                zeroCount++;
        }
        long long value = 0;
        long long weight = 1;
        int onesTaken = 0;

        for (int i = n - 1; i >= 0 && weight <= (long long)k; i--) {
            if (s[i] == '1') {
                if (value + weight <= (long long)k) {
                    value += weight;
                    onesTaken++;
                }
            }
            weight <<= 1;
        }
        return zeroCount + onesTaken;
    }
};
