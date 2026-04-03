// Last updated: 4/3/2026, 1:50:25 PM
class Solution {
    vector<vector<vector<int>>> dp;

    int solve(int i, int j, int k, vector<vector<int>>& coins) {
        if (i == 0 && j == 0) {
            if (coins[i][j] < 0 && k > 0)
                return 0;
            return coins[i][j];
        }

        if (dp[i][j][k] != INT_MIN)
            return dp[i][j][k];

        long long res = LLONG_MIN;
        if (i > 0) {
            int top = solve(i - 1, j, k, coins);
            if (top != INT_MIN)
                res = max(res, (long long)top + coins[i][j]);

            if (coins[i][j] < 0 && k > 0) {
                int top_neut = solve(i - 1, j, k - 1, coins);
                if (top_neut != INT_MIN)
                    res = max(res, (long long)top_neut);
            }
        }
        if (j > 0) {
            int left = solve(i, j - 1, k, coins);
            if (left != INT_MIN)
                res = max(res, (long long)left + coins[i][j]);

            if (coins[i][j] < 0 && k > 0) {
                int left_neut = solve(i, j - 1, k - 1, coins);
                if (left_neut != INT_MIN)
                    res = max(res, (long long)left_neut);
            }
        }

        return dp[i][j][k] = (int)res;
    }

public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size();
        int n = coins[0].size();

        dp.assign(m, vector<vector<int>>(n, vector<int>(3, INT_MIN)));
        return solve(m - 1, n - 1, 2, coins);
    }
};