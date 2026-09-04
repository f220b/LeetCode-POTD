// Last updated: 9/5/2026, 12:01:08 AM
class Solution {
public:
    int digitFrequencyScore(int n) {
        vector<int> freq(10, 0);
        while (n) {
            freq[n % 10]++;
            n /= 10;
        }
        int score = 0;
        for (int i = 0; i <= 9; i++)
            score += (i * freq[i]);
        return score;
    }
};