// Last updated: 4/3/2026, 1:49:31 PM
class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        const int INF = 1e9;

        int maxVal = 0;
        for (const auto& row : grid) {
            for (int val : row) maxVal = max(maxVal, val);
        }

        vector<vector<int>> dp(n, vector<int>(m, INF));
        vector<int> temp(maxVal + 1, INF);
        vector<int> best(maxVal + 1, INF);

        dp[n - 1][m - 1] = 0;
        temp[grid[n - 1][m - 1]] = 0;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (i == n - 1 && j == m - 1) continue;

                long long down = (i + 1 < n) ? (long long)dp[i + 1][j] + grid[i + 1][j] : INF;
                long long right = (j + 1 < m) ? (long long)dp[i][j + 1] + grid[i][j + 1] : INF;

                dp[i][j] = (int)min({(long long)INF, down, right});

                if (dp[i][j] != INF) {
                    temp[grid[i][j]] = min(temp[grid[i][j]], dp[i][j]);
                }
            }
        }

        for (int x = 0; x < k; x++) {
            best[0] = temp[0];
            for (int v = 1; v <= maxVal; v++) {
                best[v] = min(best[v - 1], temp[v]);
            }

            for (int i = n - 1; i >= 0; i--) {
                for (int j = m - 1; j >= 0; j--) {
                    if (i == n - 1 && j == m - 1) continue;

                    long long down = (i + 1 < n) ? (long long)dp[i + 1][j] + grid[i + 1][j] : INF;
                    long long right = (j + 1 < m) ? (long long)dp[i][j + 1] + grid[i][j + 1] : INF;
                    int walkCost = (int)min({(long long)INF, down, right});

                    int teleportCost = best[grid[i][j]];

                    dp[i][j] = min(walkCost, teleportCost);
                }
            }

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (dp[i][j] != INF) {
                        temp[grid[i][j]] = min(temp[grid[i][j]], dp[i][j]);
                    }
                }
            }
        }

        return dp[0][0];
    }
};