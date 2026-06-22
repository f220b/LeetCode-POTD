// Last updated: 22/6/2026, 7:41:26 pm
class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> grid(m, string(n, '#'));
        for (int i = 0; i < m; i++)
            grid[i][0] = '.';
        for (int j = 0; j < n; j++)
            grid[m - 1][j] = '.';
        return grid;
    }
};