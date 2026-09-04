// Last updated: 9/5/2026, 12:21:21 AM
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        long long continuousZeroes = 0, total = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                continuousZeroes++;
            } else {
                continuousZeroes = 0;
            }
            total += continuousZeroes;
        }
        return total;
    }
};