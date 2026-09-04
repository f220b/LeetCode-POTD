// Last updated: 9/5/2026, 12:27:55 AM
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxSum = 0, minSum = 0, currMax = 0, currMin = 0;

        for (int num : nums) {
            currMax = max(num, currMax + num);
            currMin = min(num, currMin + num);
            maxSum = max(maxSum, currMax);
            minSum = min(minSum, currMin);
        }

        return max(abs(maxSum), abs(minSum));
    }
};