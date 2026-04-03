// Last updated: 4/3/2026, 1:49:23 PM
class Solution {
public:
    using ll = long long;
    int n;
    vector<vector<ll>> dp;

    ll solve(int i, int state, vector<int>& nums) {
        if (i == n)
            return (state == 3) ? 0 : LLONG_MIN / 2;

        if (dp[i][state] != -1)
            return dp[i][state];

        ll skip = LLONG_MIN / 2;
        ll take = LLONG_MIN / 2;
        // The trionic subarray hasn't been started
        // and will skipped for the current index
        if (state == 0)
            skip = solve(i + 1, 0, nums);

        // We are in the last increment phase
        // and are ending the trionic subarray right here
        if (state == 3)
            take = nums[i];

        if (i + 1 < n) {
            int next = nums[i + 1];
            int curr = nums[i];

            // The trionic subarray is not started yet
            if (state == 0 && next > curr) {
                take = max(take, (ll)curr + solve(i + 1, 1, nums));
            }
            // We are in first increment phase
            else if (state == 1) {
                if (next > curr)
                    take = max(take, (ll)curr + solve(i + 1, 1, nums));
                else if (next < curr)
                    take = max(take, (ll)curr + solve(i + 1, 2, nums));
            }
            // We are in the decrement phase
            else if (state == 2) {
                if (next < curr)
                    take = max(take, (ll)curr + solve(i + 1, 2, nums));
                else if (next > curr)
                    take = max(take, (ll)curr + solve(i + 1, 3, nums));
            }
            // We are in last increment phase
            else if (state == 3 && next > curr) {
                take = max(take, (ll)curr + solve(i + 1, 3, nums));
            }
        }
        return dp[i][state] = max(take, skip);
    }
    long long maxSumTrionic(vector<int>& nums) {
        n = nums.size();
        dp.assign(n, vector<ll>(4, -1));
        return solve(0, 0, nums);
    }
};