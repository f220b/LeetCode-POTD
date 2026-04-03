// Last updated: 4/3/2026, 1:59:43 PM
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) // Array size is 1
            return nums[0];
        int st = 0, end = n - 1;
        while (st <= end) {
            int mid = st + (end - st) / 2;
            if (mid == 0 && nums[0] != nums[1]) {
                // Single element at start
                return nums[0];
            }
            if (mid == (n - 1) && nums[n - 1] != nums[n - 2]) {
                // Single element at end
                return nums[n - 1];
            }
            if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]) {
                // Single Element found
                return nums[mid];
            } else if (mid % 2 == 0) { // Both parts are of even length
                if (nums[mid] == nums[mid - 1]) {
                    // Single element in the right part
                    end = mid - 1;
                } else {
                    // Single element in the left part
                    st = mid + 1;
                }
            } else { // Both parts are of odd length
                if (nums[mid] == nums[mid - 1]) {
                    // Single element in the left part
                    st = mid + 1;
                } else {
                    // Single element in the right part
                    end = mid - 1;
                }
            }
        }
        return -1;
    }
};