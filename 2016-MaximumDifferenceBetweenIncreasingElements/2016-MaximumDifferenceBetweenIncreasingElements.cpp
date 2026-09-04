// Last updated: 9/5/2026, 12:24:55 AM
class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int minVal = nums[0];
        int maxDiff = -1;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > minVal) {
                maxDiff = max(maxDiff, nums[i] - minVal);
            } else {
                minVal = nums[i];
            }
        }
        return maxDiff;
    }
};
