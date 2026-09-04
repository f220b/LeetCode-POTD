// Last updated: 9/5/2026, 12:31:25 AM
class Solution {
public:
    int m, n;
    vector<vector<bool>> vis;
    vector<vector<int>> dirs[7] = {{},
                                   {{0, -1}, {0, 1}},
                                   {{-1, 0}, {1, 0}},
                                   {{0, -1}, {1, 0}},
                                   {{0, 1}, {1, 0}},
                                   {{0, -1}, {-1, 0}},
                                   {{0, 1}, {-1, 0}}};

    bool isValid(int r, int c, int pr, int pc, vector<vector<int>>& grid) {
        if (r < 0 || r >= m || c < 0 || c >= n || vis[r][c])
            return false;

        for (auto& d : dirs[grid[r][c]]) {
            if (r + d[0] == pr && c + d[1] == pc)
                return true;
        }
        return false;
    }

    bool dfs(int r, int c, vector<vector<int>>& grid) {
        if (r == m - 1 && c == n - 1)
            return true;
        vis[r][c] = true;

        for (auto& d : dirs[grid[r][c]]) {
            int nr = r + d[0];
            int nc = c + d[1];
            if (isValid(nr, nc, r, c, grid)) {
                if (dfs(nr, nc, grid))
                    return true;
            }
        }
        return false;
    }

    bool hasValidPath(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vis.assign(m, vector<bool>(n, false));
        return dfs(0, 0, grid);
    }
};