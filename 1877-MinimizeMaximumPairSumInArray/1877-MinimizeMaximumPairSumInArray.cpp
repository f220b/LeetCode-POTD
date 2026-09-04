// Last updated: 9/5/2026, 12:26:39 AM
class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int max_sum = 0;
        int n = nums.size();
        
        for (int i = 0; i < n / 2; ++i) {
            max_sum = max(max_sum, nums[i] + nums[n - 1 - i]);
        }
        
        return max_sum;
    }
};