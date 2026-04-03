// Last updated: 4/3/2026, 2:03:42 PM
class Solution {
public:
    bool isSafe(int row, int col, vector<string> board, int n) {
        int row1 = row, col1 = col;
        // Up-Left
        while (row1 >= 0 && col1 >= 0) {
            if (board[row1][col1] == 'Q')
                return false;
            row1--;
            col1--;
        }
        // Horizontal Left
        row1 = row;
        col1 = col;
        while (col1 >= 0) {
            if (board[row1][col1] == 'Q')
                return false;
            col1--;
        }
        // Bottom Left
        col1 = col;
        while (row1 < n && col1 >= 0) {
            if (board[row1][col1] == 'Q')
                return false;
            row1++;
            col1--;
        }
        return true;
    }
    void solve(vector<vector<string>>& ans, vector<string>& board, int col,
               int n) {
        if (col == n) {
            ans.push_back(board);
            return;
        }
        for (int row = 0; row < n; row++) {
            if (isSafe(row, col, board, n)) {
                board[row][col] = 'Q';
                //"board[row]" is a string
                // So board[row][col] is the character at "col" index of
                // board[row]
                solve(ans, board, col + 1, n);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        solve(ans, board, 0, n);
        return ans;
    }
};