// Last updated: 4/3/2026, 1:53:06 PM
class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size(), n = grid[0].size();
        vector<pair<int, int>> sortedQueries;
        for (int i = 0; i < queries.size(); i++) sortedQueries.push_back({queries[i], i});
        sort(sortedQueries.begin(), sortedQueries.end());

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.push({grid[0][0], 0, 0});
        visited[0][0] = true;

        int count = 0;
        vector<int> res(queries.size());
        vector<pair<int, int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};
        int qIndex = 0;

        for (auto& [val, idx] : sortedQueries) {
            while (!pq.empty() && get<0>(pq.top()) < val) {
                auto [v, x, y] = pq.top(); pq.pop();
                count++;
                for (auto& [dx, dy] : dirs) {
                    int nx = x + dx, ny = y + dy;
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny]) {
                        visited[nx][ny] = true;
                        pq.push({grid[nx][ny], nx, ny});
                    }
                }
            }
            res[idx] = count;
        }

        return res;
    }
};
