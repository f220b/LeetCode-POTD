// Last updated: 4/3/2026, 2:00:24 PM
class Solution {
public:
    int getSum(int a, int b) {
        int c;
        while (b != 0) {
            c = a & b;
            a = a ^ b;
            b = (c) << 1;
        }
        return a;
    }
};