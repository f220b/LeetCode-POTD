// Last updated: 4/3/2026, 1:50:21 PM
class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n = nums.size(), count = 0;
        for (int i = 0, j = 1, k = 2; k < n; i++, j++, k++) {
            if (((nums[i] + nums[k]) * 2) == nums[j]) {
                count++;
            }
        }
        return count;
    }
};