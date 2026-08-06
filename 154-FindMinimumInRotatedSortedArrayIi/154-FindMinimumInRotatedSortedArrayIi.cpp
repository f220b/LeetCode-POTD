// Last updated: 8/6/2026, 1:26:12 PM
class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;

        while (low < high) {
            int mid = low + ((high - low) >> 1);

            if (nums[mid] > nums[high])
                low = mid + 1;
            else if (nums[mid] < nums[high])
                high = mid;
            else
                high--;
        }
        return nums[low];
    }
};