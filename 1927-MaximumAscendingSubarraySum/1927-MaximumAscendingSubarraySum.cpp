// Last updated: 4/3/2026, 1:55:22 PM
class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int currSum = nums[0], maxSum = nums[0];
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                currSum += nums[i];
            } else {
                currSum = nums[i];
            }
            maxSum = max(currSum, maxSum);
        }
        return maxSum;
    }
};