// Last updated: 4/3/2026, 2:00:11 PM
class Solution {
private:
    bool isValid(int x, int y, int rows, int cols) {
        return x >= 0 && y >= 0 && x < rows && y < cols;
    }
    void dfs(int x, int y, int rows, int cols, vector<vector<int>>& heights,
             vector<vector<bool>>& visited) {
        visited[x][y] = true;
        vector<vector<int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        for (auto& dir : directions) {
            int nx = x + dir[0];
            int ny = y + dir[1];

            if (isValid(nx, ny, rows, cols) && !visited[nx][ny] &&
                heights[nx][ny] >= heights[x][y]) {
                dfs(nx, ny, rows, cols, heights, visited);
            }
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size(), cols = heights[0].size();
        vector<vector<bool>> pacificVisited(rows, vector<bool>(cols, false));
        vector<vector<bool>> atlanticVisited(rows, vector<bool>(cols, false));
        // Left for Pacific && right for Atlantic
        for (int i = 0; i < rows; i++) {
            dfs(i, 0, rows, cols, heights, pacificVisited);
            dfs(i, cols - 1, rows, cols, heights, atlanticVisited);
        }
        // Top for Pacific && bottom for Atlantic
        for (int j = 0; j < cols; j++) {
            dfs(0, j, rows, cols, heights, pacificVisited);
            dfs(rows - 1, j, rows, cols, heights, atlanticVisited);
        }
        vector<vector<int>> result;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (pacificVisited[i][j] && atlanticVisited[i][j])
                    result.push_back({i, j});
            }
        }
        return result;
    }
};