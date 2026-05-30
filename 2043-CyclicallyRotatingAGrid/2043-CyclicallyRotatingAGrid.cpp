// Last updated: 30/5/2026, 10:21:13 pm
class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int numLayers = min(m, n) / 2;

        for (int i = 0; i < numLayers; i++) {
            vector<int> temp;

            for (int j = i; j < n - 1 - i; j++)
                temp.push_back(grid[i][j]);
            for (int j = i; j < m - 1 - i; j++)
                temp.push_back(grid[j][n - 1 - i]);
            for (int j = n - 1 - i; j > i; j--)
                temp.push_back(grid[m - 1 - i][j]);
            for (int j = m - 1 - i; j > i; j--)
                temp.push_back(grid[j][i]);

            int len = temp.size();
            int shift = k % len;
            int idx = shift;

            for (int j = i; j < n - 1 - i; j++) {
                grid[i][j] = temp[idx % len];
                idx++;
            }
            for (int j = i; j < m - 1 - i; j++) {
                grid[j][n - 1 - i] = temp[idx % len];
                idx++;
            }
            for (int j = n - 1 - i; j > i; j--) {
                grid[m - 1 - i][j] = temp[idx % len];
                idx++;
            }
            for (int j = m - 1 - i; j > i; j--) {
                grid[j][i] = temp[idx % len];
                idx++;
            }
        }

        return grid;
    }
};