// Last updated: 9/5/2026, 12:01:02 AM
class Solution {
public:
    bool checkGoodInteger(int n) {
        int sqSum = 0, sum = 0;
        while (n > 0) {
            int d = n % 10;
            sqSum += (d * d);
            sum += d;
            if (sqSum - sum >= 50)
                return true;
            n /= 10;
        }
        return false;
    }
};