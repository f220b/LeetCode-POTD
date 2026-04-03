// Last updated: 4/3/2026, 2:04:06 PM
class Solution {
public:
    int firstIndex(vector<int> nums, int target) {
        int beg = 0, end = nums.size() - 1;
        int pos = -1;
        while (beg <= end) {
            int mid = beg + (end - beg) / 2;
            if (nums[mid] == target) {
                pos = mid;
                end = mid - 1;
            } else if (nums[mid] < target) {
                beg = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return pos;
    }
    int lastIndex(vector<int> nums, int target) {
        int beg = 0, end = nums.size() - 1;
        int pos = -1;
        while (beg <= end) {
            int mid = beg + (end - beg) / 2;
            if (nums[mid] == target) {
                pos = mid;
                beg = mid + 1;
            } else if (nums[mid] < target) {
                beg = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return pos;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        ans.push_back(firstIndex(nums, target));
        ans.push_back(lastIndex(nums, target));
        return ans;
    }
};