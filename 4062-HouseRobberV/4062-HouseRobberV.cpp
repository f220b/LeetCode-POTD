// Last updated: 4/3/2026, 1:49:02 PM
class Solution {
public:
    using ll = long long;
    int n;
    ll dp[100005][2];
    ll solve(int i, int prevRobbed, vector<int>& nums, vector<int>& colors) {
        if (i == n)
            return 0;
        if (dp[i][prevRobbed] != -1)
            return dp[i][prevRobbed];

        ll notRob = solve(i + 1, 0, nums, colors);
        ll rob = 0;
        if (i == 0 || prevRobbed == 0 || colors[i] != colors[i - 1])
            rob = (ll)nums[i] + solve(i + 1, 1, nums, colors);

        return dp[i][prevRobbed] = max(rob, notRob);
    }
    long long rob(vector<int>& nums, vector<int>& colors) {
        n = nums.size();
        for (int i = 0; i <= n; i++) {
            dp[i][0] = -1;
            dp[i][1] = -1;
        }
        return solve(0, 0, nums, colors);
    }
};