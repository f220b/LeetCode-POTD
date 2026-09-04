// Last updated: 9/5/2026, 12:05:27 AM
class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int helper(int i, vector<int>& nums, int curr, int target) {
        if (i == n)
            return (curr == target) ? 0 : -1e9;
        if (dp[i][curr] != -1)
            return dp[i][curr];

        int include = 1 + helper(i + 1, nums, curr ^ nums[i], target);
        int exclude = helper(i + 1, nums, curr, target);

        return dp[i][curr] = max(include, exclude);
    }
    int minRemovals(vector<int>& nums, int target) {
        n = nums.size();
        int maxValue = target;
        for(int x : nums)
            maxValue = max(maxValue, x);
        
        int limit = 1;
        while(limit <= maxValue)
            limit <<= 1;
        dp.assign(n, vector<int>(limit, -1));
        int maxKept = helper(0, nums, 0, target);
        if(maxKept < 0)
            return -1;
        
        return n - maxKept;
    }
};