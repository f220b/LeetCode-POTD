// Last updated: 9/5/2026, 12:38:10 AM
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int beg = 0, end = nums.size() - 1;
        while (beg <= end) {
            int mid = (beg + end) >> 1;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
                end = mid - 1;
            else
                beg = mid + 1;
        }
        return -1;
    }
};