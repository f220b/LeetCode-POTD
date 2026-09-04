// Last updated: 9/5/2026, 12:22:43 AM
class Solution {
public:
    bool binary(vector<int>& nums, int original) {
        int low = 0, high = nums.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == original)
                return true;
            else if (nums[mid] < original)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return false;
    }
    int findFinalValue(vector<int>& nums, int original) {
        sort(nums.begin(), nums.end());
        while (true) {
            if (binary(nums, original))
                original = 2 * original;
            else
                break;
        }
        return original;
    }
};