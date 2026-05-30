// Last updated: 30/5/2026, 10:22:19 pm
class Solution {
    int row, col;
    int vis[501][501];
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    bool dfs(int r, int c, int pr, int pc, char val,
             vector<vector<char>>& grid) {
        vis[r][c] = 1;

        for (int i = 0; i < 4; i++) {
            int nr = r + dx[i];
            int nc = c + dy[i];

            if (nr >= 0 && nr < row && nc >= 0 && nc < col &&
                grid[nr][nc] == val) {
                if (nr == pr && nc == pc)
                    continue;
                if (vis[nr][nc])
                    return true;
                if (dfs(nr, nc, r, c, val, grid))
                    return true;
            }
        }
        return false;
    }

public:
    bool containsCycle(vector<vector<char>>& grid) {
        row = grid.size();
        col = grid[0].size();

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                vis[i][j] = 0;
            }
        }

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (!vis[i][j]) {
                    if (dfs(i, j, -1, -1, grid[i][j], grid))
                        return true;
                }
            }
        }
        return false;
    }
};