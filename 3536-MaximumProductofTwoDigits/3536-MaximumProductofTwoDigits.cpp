// Last updated: 7/25/2026, 3:37:54 PM
1class Solution {
2public:
3    int maxProduct(int n) {
4        int max1 = -1, max2 = -1;
5        while (n != 0) {
6            int rem = n % 10;
7            if (max1 <= rem) {
8                max2 = max1;
9                max1 = rem;
10            } else if (max2 < rem) {
11                max2 = rem;
12            }
13            n /= 10;
14        }
15        return max1 * max2;
16    }
17};