// Last updated: 9/5/2026, 12:00:36 AM
class Solution {
public:
    using vi = vector<int>;
    int digitRange(int x) {
        int maxD = 0, minD = 9;
        while (x) {
            int d = x % 10;
            maxD = max(maxD, d);
            minD = min(minD, d);
            x /= 10;
        }
        return maxD - minD;
    }
    int maxDigitRange(vector<int>& nums) {
        vi dig(10, 0);
        for (int n : nums) {
            int digRange = digitRange(n);
            dig[digRange] += n;
        }
        for (int i = 9; i >= 0; i--) {
            if (dig[i])
                return dig[i];
        }
        return -1;
    }
};