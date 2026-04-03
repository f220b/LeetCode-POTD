// Last updated: 4/3/2026, 1:56:51 PM
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>, greater<>>
            pq;
        vector<vector<int>> cost(m, vector<int>(n, INT_MAX));
        pq.push({0, {0, 0}});
        cost[0][0] = 0;

        while (!pq.empty()) {
            auto [currentCost, cell] = pq.top();
            int x = cell.first, y = cell.second;
            pq.pop();

            if (x == m - 1 && y == n - 1)
                return currentCost;

            for (int i = 0; i < 4; ++i) {
                int nx = x + directions[i][0];
                int ny = y + directions[i][1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    int newCost = currentCost + (grid[x][y] != i + 1);
                    if (newCost < cost[nx][ny]) {
                        cost[nx][ny] = newCost;
                        pq.push({newCost, {nx, ny}});
                    }
                }
            }
        }
        return -1;
    }
};
