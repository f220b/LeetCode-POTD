// Last updated: 4/3/2026, 1:51:41 PM
class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> prefixSum(m, vector<int>(n, 0));
        int cnt = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int top = (i >= 1) ? prefixSum[i - 1][j] : 0;
                int left = (j >= 1) ? prefixSum[i][j - 1] : 0;
                int top_left = (i >= 1 && j >= 1) ? prefixSum[i - 1][j - 1] : 0;
                prefixSum[i][j] = top + left - top_left + grid[i][j];
                if (prefixSum[i][j] <= k)
                    cnt++;
            }
        }
        return cnt;
    }
};