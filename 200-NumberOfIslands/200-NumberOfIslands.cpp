// Last updated: 4/3/2026, 2:01:27 PM
class Solution {
public:
    int m, n;
    vector<vector<int>> visited;
    void dfs(int i, int j, vector<vector<char>>& grid) {
        visited[i][j] = 1;
        vector<int> di = {0, 1, 0, -1};
        vector<int> dj = {1, 0, -1, 0};

        for (int k = 0; k < 4; k++) {
            int newI = i + di[k], newJ = j + dj[k];
            if (newI >= 0 && newJ >= 0 && newI < m && newJ < n &&
                grid[newI][newJ] == '1' && !visited[newI][newJ])
                dfs(newI, newJ, grid);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        visited.assign(m, vector<int>(n, 0));

        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    count++;
                    dfs(i, j, grid);
                }
            }
        }
        return count;
    }
};