// Last updated: 9/5/2026, 12:21:45 AM
class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int count = 1;
        int start = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] - start > k) {
                count++;
                start = nums[i];
            }
        }
        return count;
    }
};
