// Last updated: 4/3/2026, 1:53:18 PM
class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int count = 0;
        while (num2) {
            num2 = num2 & (num2 - 1);
            count++;
        }
        int res = 0;
        for (int i = 31; i >= 0 && count; i--) {
            if (num1 & (1 << i)) {
                count--;
                res += (1 << i);
            }
        }
        for (int i = 0; i < 32 && count; i++) {
            if (!(num1 & (1 << i))) {
                count--;
                res += (1 << i);
            }
        }
        return res;
    }
};