// Last updated: 4/3/2026, 1:59:22 PM
class Solution {
public:
    bool hasAlternatingBits(int n) {
        int lastBit = -1;
        while (n) {
            if ((n & 1) == lastBit)
                return false;
            lastBit = n & 1;
            n = n >> 1;
        }
        return true;
    }
};