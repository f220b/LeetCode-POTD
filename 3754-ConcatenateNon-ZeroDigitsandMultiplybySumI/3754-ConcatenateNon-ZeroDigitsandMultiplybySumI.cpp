// Last updated: 7/7/2026, 1:02:11 PM
1class Solution {
2public:
3    using ll = long long;
4    long long sumAndMultiply(int n) {
5        int x = 0, sum = 0;
6        int mul = 1;
7
8        while (n) {
9            int d = n % 10;
10            if (d) {
11                x = x + (d * mul);
12                mul *= 10;
13            }
14            sum += d;
15            n /= 10;
16        }
17        return (ll)x * sum;
18    }
19};