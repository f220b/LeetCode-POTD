// Last updated: 9/5/2026, 12:30:23 AM
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left = 0, right = 0, zeros = 0, res = 0;

        while (right < nums.size()) {
            if (nums[right] == 0)
                zeros++;
            while (zeros > 1) {
                if (nums[left] == 0)
                    zeros--;
                left++;
            }
            res = max(res, right - left);
            right++;
        }

        return res;
    }
};