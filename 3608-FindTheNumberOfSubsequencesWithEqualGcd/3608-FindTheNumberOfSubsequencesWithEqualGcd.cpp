// Last updated: 7/18/2026, 11:54:43 PM
class Solution {
public:
    const int MOD = 1e9 + 7;
    using vi = vector<int>;
    int n;
    int dp[201][201][201];

    int helper(int i, int g1, int g2, vi& nums) {
        if (i == n)
            return (g1 != 0 && g1 == g2);

        int ans = 0;
        if (dp[i][g1][g2] != -1)
            return dp[i][g1][g2];

        ans = helper(i + 1, g1, g2, nums);
        int ng1 = (g1 == 0) ? nums[i] : gcd(g1, nums[i]);
        ans = (ans + helper(i + 1, ng1, g2, nums)) % MOD;

        int ng2 = (g2 == 0) ? nums[i] : gcd(g2, nums[i]);
        ans = (ans + helper(i + 1, g1, ng2, nums)) % MOD;

        return dp[i][g1][g2] = ans;
    }
    int subsequencePairCount(vector<int>& nums) {
        n = nums.size();
        memset(dp, -1, sizeof(dp));
        return helper(0, 0, 0, nums);
    }
};