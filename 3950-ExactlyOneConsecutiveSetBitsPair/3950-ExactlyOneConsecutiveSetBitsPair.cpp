// Last updated: 9/5/2026, 12:01:23 AM
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