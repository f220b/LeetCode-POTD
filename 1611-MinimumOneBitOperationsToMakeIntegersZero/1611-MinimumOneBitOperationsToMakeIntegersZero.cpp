// Last updated: 9/5/2026, 12:29:03 AM
class Solution {
public:
    int minimumOneBitOperations(int n) {
        if (n == 0)
            return 0;
        int k = 31 - __builtin_clz(n); // position of the most significant bit
        int mask = 1 << k;
        return (1 << (k + 1)) - 1 - minimumOneBitOperations(n ^ mask);
    }
};
