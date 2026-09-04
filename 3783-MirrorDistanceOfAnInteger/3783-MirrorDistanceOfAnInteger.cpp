// Last updated: 9/5/2026, 12:04:33 AM
class Solution {
public:
    int mirrorDistance(int n) {
        int num = n, rev = 0;
        while (num > 0) {
            rev = rev * 10 + num % 10;
            num /= 10;
        }
        return abs(rev - n);
    }
};