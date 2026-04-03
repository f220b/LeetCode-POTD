// Last updated: 4/3/2026, 2:00:41 PM
class Solution {
public:
    int solve(int i, int lastIdx, vector<int>& nums, vector<vector<int>>& dp) {
        if (i == nums.size())
            return 0;
        if (dp[i][lastIdx] != -1)
            return dp[i][lastIdx];

        int notPick = solve(i + 1, lastIdx, nums, dp);
        int pick = 0;
        if (lastIdx == 0 || nums[lastIdx - 1] < nums[i])
            pick = 1 + solve(i + 1, i + 1, nums, dp);

        return dp[i][lastIdx] = max(pick, notPick);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return solve(0, 0, nums, dp);
    }
};