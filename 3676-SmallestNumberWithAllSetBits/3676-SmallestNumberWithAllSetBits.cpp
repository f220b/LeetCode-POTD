// Last updated: 4/3/2026, 1:50:27 PM
class Solution {
public:
    int smallestNumber(int n) {
        int bits = floor(log2(n)) + 1;
        int result = (1 << bits) - 1;
        return result;
    }
};