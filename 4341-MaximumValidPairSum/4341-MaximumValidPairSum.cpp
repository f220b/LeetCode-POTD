// Last updated: 7/6/2026, 8:50:49 AM
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