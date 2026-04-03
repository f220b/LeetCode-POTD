// Last updated: 4/3/2026, 1:57:38 PM
class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> rows(m + 1, vector<int>(n + 1, 0));
        vector<vector<int>> cols(m + 1, vector<int>(n + 1, 0));

        vector<vector<int>> diag1(m + 1, vector<int>(n + 1, 0));
        vector<vector<int>> diag2(m + 1, vector<int>(n + 2, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                rows[i + 1][j + 1] = rows[i + 1][j] + grid[i][j];
                cols[i + 1][j + 1] = cols[i][j + 1] + grid[i][j];
                diag1[i + 1][j + 1] = diag1[i][j] + grid[i][j];
                diag2[i + 1][j + 1] = diag2[i][j + 2] + grid[i][j];
            }
        }
        for (int k = min(m, n); k > 0; k--) {
            for (int i = 0; i + k <= m; i++) {
                for (int j = 0; j + k <= n; j++) {
                    int sum = rows[i + 1][j + k] - rows[i + 1][j];
                    bool flag = true;

                    for (int r = 0; r < k && flag; r++)
                        flag &= (rows[i + r + 1][j + k] - rows[i + r + 1][j] ==
                                 sum);
                    for (int c = 0; c < k && flag; c++)
                        flag &= (cols[i + k][j + c + 1] - cols[i][j + c + 1] ==
                                 sum);

                    flag &= (diag1[i + k][j + k] - diag1[i][j] == sum);
                    flag &= (diag2[i + k][j + 1] - diag2[i][j + k + 1] == sum);
                    if (flag)
                        return k;
                }
            }
        }
        return 1;
    }
};
