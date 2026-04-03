// Last updated: 4/3/2026, 2:02:18 PM
class Solution {
public:
    int m, n;
    vector<vector<int>> visited;
    void dfs(int i, int j, vector<vector<char>>& board) {
        // Check if its 'O'
        // Check if it isn't visited yet
        if (board[i][j] != 'O' || visited[i][j])
            return;

        // Mark as visited
        visited[i][j] = 1;
        vector<int> di = {0, 1, 0, -1};
        vector<int> dj = {1, 0, -1, 0};
        for (int k = 0; k < 4; k++) {
            int newI = i + di[k];
            int newJ = j + dj[k];

            // Check if (i, j) is in the range
            if (newI >= 0 && newJ >= 0 && newI < m && newJ < n)
                dfs(newI, newJ, board);
        }
    }
    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();
        visited.assign(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            dfs(i, 0, board);
            dfs(i, n - 1, board);
        }
        for (int j = 0; j < n; j++) {
            dfs(0, j, board);
            dfs(m - 1, j, board);
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O' && !visited[i][j])
                    board[i][j] = 'X';
            }
        }
    }
};