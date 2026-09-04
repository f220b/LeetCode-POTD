// Last updated: 9/5/2026, 12:00:51 AM
class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int n = nums.size();
        int maxI = nums[0];
        int maxSum = INT_MIN;
        for (int j = k; j < n; j++) {
            maxI = max(maxI, nums[j - k]);
            maxSum = max(maxSum, maxI + nums[j]);
        }
        return maxSum;
    }
};