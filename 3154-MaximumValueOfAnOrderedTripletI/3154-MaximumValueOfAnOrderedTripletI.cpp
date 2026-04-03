// Last updated: 4/3/2026, 1:52:18 PM
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> right_max(n, 0);
        int maximum = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            right_max[i] = maximum;
            maximum = max(maximum, nums[i]);
        }
        int max_left = nums[0];
        long long max_triplet = 0;
        for (int i = 1; i < (n - 1); i++) {
            long long value = (long long)(max_left - nums[i]) * right_max[i];
            max_triplet = max(max_triplet, value);
            max_left = max(nums[i], max_left);
        }
        return max_triplet;
    }
};