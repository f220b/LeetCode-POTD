// Last updated: 14/6/2026, 8:11:49 am
1class Solution {
2public:
3    bool checkGoodInteger(int n) {
4        int sqSum = 0, sum = 0;
5        while (n > 0) {
6            int d = n % 10;
7            sqSum += (d * d);
8            sum += d;
9            if (sqSum - sum >= 50)
10                return true;
11            n /= 10;
12        }
13        return false;
14    }
15};