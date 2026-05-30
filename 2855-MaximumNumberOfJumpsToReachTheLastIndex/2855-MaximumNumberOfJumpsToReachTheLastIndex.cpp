// Last updated: 30/5/2026, 10:19:24 pm
class Solution {
    vector<int> dp;
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        dp.assign(n, -1);
        dp[0] = 0;
        
        for (int j = 1; j < n; ++j) {
            for (int i = 0; i < j; ++i) {
                if (dp[i] != -1 && abs(nums[j] - nums[i]) <= target) {
                    dp[j] = max(dp[j], dp[i] + 1);
                }
            }
        }
        
        return dp[n - 1];
    }
};