// Last updated: 25/4/2026, 11:30:54 pm
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