// Last updated: 4/3/2026, 2:01:07 PM
class Solution {
public:
    bool isPowerOfTwo(int n) { return n > 0 && (n & (n - 1)) == 0; }
};