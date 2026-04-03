// Last updated: 4/3/2026, 1:51:12 PM
class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int cnt = 0;
        vector<vector<int>> countX(m, vector<int>(n, 0));
        vector<vector<int>> countY(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                countX[i][j] = (grid[i][j] == 'X');
                countY[i][j] = (grid[i][j] == 'Y');

                if (i >= 1) {
                    countX[i][j] += countX[i - 1][j];
                    countY[i][j] += countY[i - 1][j];
                }
                if (j >= 1) {
                    countX[i][j] += countX[i][j - 1];
                    countY[i][j] += countY[i][j - 1];
                }
                if (i >= 1 && j >= 1) {
                    countX[i][j] -= countX[i - 1][j - 1];
                    countY[i][j] -= countY[i - 1][j - 1];
                }
                if (countX[i][j] == countY[i][j] && countX[i][j] > 0)
                    cnt++;
            }
        }
        return cnt;
    }
};