// Last updated: 6/6/2026, 8:09:16 PM
1class Solution {
2public:
3    bool consecutiveSetBits(int n) {
4        int count = 0;
5        for (int i = 1; i < 32; i++) {
6            if (((n >> i) & 1) && (n >> (i - 1) & 1))
7                count++;
8        }
9        return (count == 1);
10    }
11};