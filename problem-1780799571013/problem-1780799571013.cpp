// Last updated: 7/6/2026, 8:02:51 am
1class Solution {
2public:
3    int sumOfGoodIntegers(int n, int k) {
4        int sum = 0;
5        for (int i = max(1, n - k); i <= n + k; i++) {
6            if (!(n & i))
7                sum += i;
8        }
9        return sum;
10    }
11};