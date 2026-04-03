// Last updated: 4/3/2026, 1:56:38 PM
class Solution {
public:
    int maxScore(string s) {
        int totalOnes = 0, leftZeros = 0, leftOnes = 0, maxScore = 0;

        for (char c : s) {
            if (c == '1')
                totalOnes++;
        }
        int ptr = 0;

        while(ptr < s.length() - 1) {
            if (s[ptr] == '0') {
                leftZeros++;
            } else {
                leftOnes++;
            }

            int rightOnes = totalOnes - leftOnes;
            int score = leftZeros + rightOnes;
            maxScore = max(maxScore, score);
            ptr++;
        }

        return maxScore;
    }
};