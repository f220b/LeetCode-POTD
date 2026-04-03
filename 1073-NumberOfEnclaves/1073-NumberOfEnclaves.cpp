// Last updated: 4/3/2026, 1:57:55 PM
class Solution {
public:
    int m, n;
    vector<vector<int>> visited;

    void dfs(int i, int j, vector<vector<int>>& grid) {
        // Not land or already visited
        if (grid[i][j] != 1 || visited[i][j])
            return;

        // Mark as visited
        visited[i][j] = 1;
        vector<int> di = {0, 1, 0, -1};
        vector<int> dj = {1, 0, -1, 0};
        for (int k = 0; k < 4; k++) {
            int ni = i + di[k];
            int nj = j + dj[k];
            // If in grid range
            if (ni >= 0 && nj >= 0 && ni < m && nj < n)
                dfs(ni, nj, grid);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        visited.assign(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            dfs(i, 0, grid);
            dfs(i, n - 1, grid);
        }
        for (int j = 0; j < n; j++) {
            dfs(0, j, grid);
            dfs(m - 1, j, grid);
        }
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && !visited[i][j])
                    count++;
            }
        }
        return count;
    }
};