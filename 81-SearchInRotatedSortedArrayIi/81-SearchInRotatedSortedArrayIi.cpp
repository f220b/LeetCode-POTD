// Last updated: 4/3/2026, 2:03:08 PM
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int beg = 0, end = nums.size() - 1;
        while (beg <= end) {
            int mid = (beg + end) >> 1;
            if (nums[mid] == target) // Target found
                return true;
            if (nums[beg] == nums[mid] && nums[mid] == nums[end]) {
                // 1st, mid, last index have same value
                // {3, 1, 2, 3, 3, 3}
                beg++;
                end--;
                continue;
            }
            if (nums[beg] <= nums[mid]) { // Left sorted
                if (nums[beg] <= target && target <= nums[mid]) {
                    // Target in left half
                    end = mid - 1;
                } else { // Target in right half
                    beg = mid + 1;
                }
            } else { // Right sorted
                if (nums[mid] <= target && target <= nums[end]) {
                    // Target in right half
                    beg = mid + 1;
                } else { // Target in left half
                    end = mid - 1;
                }
            }
        }
        return false;
    }
};