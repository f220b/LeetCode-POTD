// Last updated: 7/18/2026, 11:59:07 PM
class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<char>> res(n, vector<char>(m, '.'));

        for (int i = 0; i < m; i++) {
            int p = n - 1;
            for (int j = n - 1; j >= 0; j--) {
                if (grid[i][j] == '*') {
                    res[j][m - 1 - i] = '*';
                    p = j - 1;
                } else if (grid[i][j] == '#')
                    res[p--][m - 1 - i] = '#';
            }
        }
        return res;
    }
};