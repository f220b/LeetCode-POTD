// Last updated: 9/5/2026, 12:31:42 AM
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int row = 0, col = n - 1, count = 0;
        while (row < m && col >= 0) {
            if (grid[row][col] >= 0)
                row++;
            else {
                count += (m - row);
                col--;
            }
        }
        return count;
    }
};