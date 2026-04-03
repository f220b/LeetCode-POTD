// Last updated: 4/3/2026, 1:56:09 PM
class Solution {
public:
    char findKthBit(int n, int k) {
        if (k == 1)
            return '0';

        long long mid = (((1 << n) - 1) >> 1) + 1;
        if (k == mid)
            return '1';
        else if (k > mid) {
            char ch = findKthBit(n, 2 * mid - k);
            return (ch == '1') ? '0' : '1';
        }
        return findKthBit(n - 1, k);
    }
};