// Last updated: 4/30/2026, 3:44:14 PM
class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>> dp(
            m + 1, vector<vector<int>>(n + 1, vector<int>(k + 1, INT_MIN)));

        for (int rem = 0; rem <= k; rem++) {
            int cell = grid[m - 1][n - 1];
            int cost = (cell == 1 || cell == 2) ? 1 : 0;
            if (rem >= cost)
                dp[m - 1][n - 1][rem] = cell;
        }

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (i == m - 1 && j == n - 1)
                    continue;

                for (int rem = 0; rem <= k; rem++) {
                    int cost = (grid[i][j] == 1 || grid[i][j] == 2) ? 1 : 0;
                    if (rem < cost)
                        continue;

                    int right = dp[i][j + 1][rem - cost];
                    int down = dp[i + 1][j][rem - cost];
                    dp[i][j][rem] = grid[i][j] + max(right, down);
                }
            }
        }
        int result = dp[0][0][k];
        return (result < 0) ? -1 : result;
    }
};