// Last updated: 4/3/2026, 1:58:40 PM
class Solution {
public:
    bool isMagicSquare(vector<vector<int>>& grid, int r, int c) {
        int sum = grid[r][c] + grid[r][c + 1] + grid[r][c + 2];
        unordered_set<int> st;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int num = grid[r + i][c + j];
                if (num == 0 || num > 9 || st.count(num))
                    return false;
                st.insert(num);
            }
        }
        for (int i = 0; i < 3; i++) {
            if (grid[r][c + i] + grid[r + 1][c + i] + grid[r + 2][c + i] != sum)
                return false;
            if (grid[r + i][c] + grid[r + i][c + 1] + grid[r + i][c + 2] != sum)
                return false;
        }
        if (grid[r][c] + grid[r + 1][c + 1] + grid[r + 2][c + 2] != sum)
            return false;
        if (grid[r + 2][c] + grid[r + 1][c + 1] + grid[r][c + 2] != sum)
            return false;

        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        int count = 0;
        for (int i = 0; i < row - 2; i++) {
            for (int j = 0; j < col - 2; j++) {
                if (isMagicSquare(grid, i, j))
                    count++;
            }
        }
        return count;
    }
};