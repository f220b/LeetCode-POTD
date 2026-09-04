// Last updated: 9/5/2026, 12:26:49 AM
class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int minDiff = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target)
                minDiff = min(minDiff, abs(i - start));
        }
        return minDiff;
    }
};