// Last updated: 2/5/2026, 11:40:14 pm
1class Solution {
2public:
3    int rotatedDigits(int n) {
4        vector<int> dp(n + 1, 0);
5        int count = 0;
6
7        for (int i = 0; i <= n; i++) {
8            if (i < 10) {
9                if (i == 0 || i == 1 || i == 8)
10                    dp[i] = 1;
11                else if (i == 2 || i == 5 || i == 6 || i == 9) {
12                    dp[i] = 2;
13                    count++;
14                } else
15                    dp[i] = 0;
16            } else {
17                int a = dp[i / 10];
18                int b = dp[i % 10];
19
20                if (a == 1 && b == 1)
21                    dp[i] = 1;
22                else if (a >= 1 && b >= 1) {
23                    dp[i] = 2;
24                    count++;
25                } else
26                    dp[i] = 0;
27            }
28        }
29
30        return count;
31    }
32};