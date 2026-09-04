// Last updated: 9/5/2026, 12:23:26 AM
class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int freq[26][26] = {0};
        int palindromeCount = 0;
        int middleCount = 0;

        for (string str : words) {
            int a = str[0] - 'a';
            int b = str[1] - 'a';

            if (freq[b][a] > 0) {
                palindromeCount += 4;
                freq[b][a]--;
                if (a == b)
                    middleCount--;
            } else {
                freq[a][b]++;
                if (a == b)
                    middleCount++;
            }
        }
        if (middleCount > 0)
            palindromeCount += 2;
        return palindromeCount;
    }
};
