// Last updated: 4/3/2026, 1:52:20 PM
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
        int left_max = nums[0];
        long long max_triplet = 0;
        for (int i = 1; i < n - 1; i++) {
            long long curr_triplet = (long long)(left_max - nums[i]) * right_max[i];
            max_triplet = max(max_triplet, curr_triplet);
            left_max = max(left_max, nums[i]);
        }
        return max_triplet;
    }
};