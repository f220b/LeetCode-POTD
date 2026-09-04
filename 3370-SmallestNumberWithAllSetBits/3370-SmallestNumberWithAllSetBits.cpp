// Last updated: 9/5/2026, 12:11:19 AM
class Solution {
public:
    int smallestNumber(int n) {
        int bits = floor(log2(n)) + 1;
        int result = (1 << bits) - 1;
        return result;
    }
};