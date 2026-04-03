// Last updated: 4/3/2026, 2:03:26 PM
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = grid[0][0];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0)
                    continue;
                int up = INT_MAX, left = INT_MAX;
                if (i - 1 >= 0)
                    up = grid[i][j] + dp[i - 1][j];
                if (j - 1 >= 0)
                    left = grid[i][j] + dp[i][j - 1];

                dp[i][j] = min(up, left);
            }
        }
        return dp[m - 1][n - 1];
    }
};