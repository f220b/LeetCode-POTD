// Last updated: 4/3/2026, 1:58:54 PM
class Solution {
public:
    bool isValid(int i, int j, int n) {
        return i >= 0 && j >= 0 && i < n && j < n;
    }

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
            pq;

        pq.push({grid[0][0], 0, 0});
        visited[0][0] = true;
        int minTime = 0;

        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            int t = cur[0], i = cur[1], j = cur[2];
            minTime = max(minTime, t);
            if (i == n - 1 && j == n - 1)
                return minTime;

            for (auto& d : dirs) {
                int ni = i + d[0], nj = j + d[1];
                if (isValid(ni, nj, n) && !visited[ni][nj]) {
                    visited[ni][nj] = true;
                    pq.push({grid[ni][nj], ni, nj});
                }
            }
        }
        return minTime;
    }
};
