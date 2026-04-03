// Last updated: 4/3/2026, 1:55:58 PM
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
