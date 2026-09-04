// Last updated: 9/5/2026, 12:37:02 AM
class Solution {
public:
    int getDigitCount(int num) {
        int ans = 0;
        while (num) {
            int d = num % 10;
            ans += pow(10, d);
            num /= 10;
        }
        return ans;
    }
    bool reorderedPowerOf2(int n) {
        int digitCount = getDigitCount(n);
        for (int i = 0; i < 30; i++) {
            int newNum = getDigitCount(1 << i);
            if (newNum == digitCount)
                return true;
        }
        return false;
    }
};