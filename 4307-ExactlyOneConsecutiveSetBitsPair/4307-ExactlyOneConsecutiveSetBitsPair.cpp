// Last updated: 8/6/2026, 11:41:14 pm
class Solution {
public:
    bool consecutiveSetBits(int n) {
        int count = 0;
        for (int i = 1; i < 32; i++) {
            if (((n >> i) & 1) && (n >> (i - 1) & 1))
                count++;
        }
        return (count == 1);
    }
};