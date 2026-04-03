// Last updated: 4/3/2026, 1:58:05 PM
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int freshCount = 0;
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> visited(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // Check if this orange is rotten
                // If yes, store its coordinates
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    visited[i][j] = 2;
                } else if (grid[i][j] == 1)
                    freshCount++;
            }
        }
        vector<int> di = {1, 0, -1, 0};
        vector<int> dj = {0, -1, 0, 1};
        int time = 0;
        while (!q.empty()) {
            auto [i, j] = q.front().first;
            int currTime = q.front().second;
            q.pop();
            time = max(currTime, time);

            for (int k = 0; k < 4; k++) {
                int newI = i + di[k];
                int newJ = j + dj[k];
                // Check if this new neighbour lies in the matrix range
                // and is not visited yet
                // and has a fresh orange
                if (newI >= 0 && newI < m && newJ >= 0 && newJ < n &&
                    visited[newI][newJ] != 2 && grid[newI][newJ] == 1) {
                    q.push({{newI, newJ}, currTime + 1});
                    visited[newI][newJ] = 2;
                    freshCount--;
                }
            }
        }
        return freshCount == 0 ? time : -1;
    }
};