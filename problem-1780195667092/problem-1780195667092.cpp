// Last updated: 31/5/2026, 8:17:47 am
1class Solution {
2public:
3    int digitFrequencyScore(int n) {
4        vector<int> freq(10, 0);
5        while (n) {
6            freq[n % 10]++;
7            n /= 10;
8        }
9        int score = 0;
10        for (int i = 0; i <= 9; i++)
11            score += (i * freq[i]);
12        return score;
13    }
14};