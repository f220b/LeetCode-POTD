// Last updated: 4/3/2026, 1:54:48 PM
class Solution {
public:
    int r, c;
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    bool bfs(vector<vector<int>>& grid, int i, int j) {
        queue<pair<int, int>> q;
        q.push({i, j});
        grid[i][j] = 1;

        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            if (x == r - 1)
                return true;

            for (auto dir : directions) {
                int newX = x + dir[0];
                int newY = y + dir[1];

                if (newX >= 0 && newX < r && newY >= 0 && newY < c &&
                    grid[newX][newY] == 0) {
                    grid[newX][newY] = 1;
                    q.push({newX, newY});
                }
            }
        }
        return false;
    }
    bool canCross(vector<vector<int>>& cells, int mid) {
        vector<vector<int>> grid(r, vector<int>(c, 0));
        for (int i = 0; i <= mid; i++) {
            int x = cells[i][0] - 1;
            int y = cells[i][1] - 1;
            grid[x][y] = 1;
        }
        for (int j = 0; j < c; j++) {
            if (grid[0][j] == 0 && bfs(grid, 0, j))
                return true;
        }
        return false;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        r = row;
        c = col;
        int n = cells.size();
        int low = 0, high = n - 1;

        int ans = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canCross(cells, mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans + 1;
    }
};