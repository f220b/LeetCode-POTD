// Last updated: 22/6/2026, 7:41:22 pm
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