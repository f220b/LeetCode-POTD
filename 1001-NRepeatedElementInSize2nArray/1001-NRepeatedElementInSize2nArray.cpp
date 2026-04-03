// Last updated: 4/3/2026, 1:58:14 PM
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int len = nums.size();
        for (int i = 0; i < len - 2; i++) {
            if (nums[i] == nums[i + 1] || nums[i] == nums[i + 2])
                return nums[i];
        }
        // If not found yet, then it is the last element
        return nums[len - 1];
    }
};