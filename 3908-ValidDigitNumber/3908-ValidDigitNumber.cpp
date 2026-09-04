// Last updated: 9/5/2026, 12:01:59 AM
class Solution {
public:
    bool validDigit(int n, int x) {
        bool exist = false;
        int dig;
        while (n > 0) {
            dig = n % 10;
            if (dig == x)
                exist = true;
            n /= 10;
        }
        return (exist && dig != x);
    }
};