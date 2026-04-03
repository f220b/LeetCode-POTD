// Last updated: 4/3/2026, 2:04:04 PM
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int beg = -0, end = nums.size() - 1, ans = -1;
        if (nums[0] >= target)
            return 0;
        if (nums[nums.size() - 1] < target)
            return nums.size();
        while (beg <= end) {
            int mid = (beg + end) >> 1;
            if (nums[mid] >= target) {
                ans = mid;
                end = mid - 1;
            } else {
                beg = mid + 1;
            }
        }
        return ans;
    }
};