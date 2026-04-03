// Last updated: 4/3/2026, 1:48:21 PM
class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int n = nums.size();
        int lastOne = -1, lastTwo = -1, minDiff = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                if (lastTwo != -1)
                    minDiff = min(minDiff, abs(i - lastTwo));
                lastOne = i;
            } else if (nums[i] == 2) {
                if (lastOne != -1)
                    minDiff = min(minDiff, abs(i - lastOne));
                lastTwo = i;
            }
        }
        return (minDiff == INT_MAX) ? -1 : minDiff;
    }
};