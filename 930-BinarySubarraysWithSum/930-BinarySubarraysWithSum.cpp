// Last updated: 9/5/2026, 12:36:22 AM
class Solution {
public:
    int lessThanOrEqualGoal(vector<int>& nums, int goal) {
        if (goal < 0)
            return 0;
        int left = 0, right = 0;
        int count = 0, sum = 0;
        int n = nums.size();

        while (right < n) {
            sum += nums[right];
            while (sum > goal) {
                sum -= nums[left];
                left++;
            }
            count += right - left + 1;
            right++;
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return lessThanOrEqualGoal(nums, goal) -
               lessThanOrEqualGoal(nums, goal - 1);
    }
};