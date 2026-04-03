// Last updated: 4/3/2026, 1:55:38 PM
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