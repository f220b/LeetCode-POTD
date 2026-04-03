// Last updated: 4/3/2026, 1:50:55 PM
class Solution {
public:
    bool isIncreasing(vector<int>& nums, int l, int r) {
        for (int i = l + 1; i <= r; i++) {
            if (nums[i] <= nums[i - 1])
                return false;
        }
        return true;
    }
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        for (int a = 0; a + 2 * k <= n; a++) {
            if (isIncreasing(nums, a, a + k - 1) &&
                isIncreasing(nums, a + k, a + 2 * k - 1))
                return true;
        }
        return false;
    }
};
