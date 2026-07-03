// Last updated: 7/3/2026, 10:27:37 AM
#define ff first
#define ss second
class Solution {
public:
    using vi = vector<int>;
    using pp = pair<int, int>;
    vi di = {0, 1, 0, -1};
    vi dj = {1, 0, -1, 0};
    int m, n;
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        m = grid.size();
        n = grid[0].size();
        vector<vi> dist(m, vi(n, 1e9));
        deque<pp> dq;

        dist[0][0] = grid[0][0];
        dq.push_front({0, 0});

        while (!dq.empty()) {
            auto [i, j] = dq.front();
            dq.pop_front();

            if (i == m - 1 && j == n - 1)
                break;

            for (int k = 0; k < 4; k++) {
                int ni = i + di[k];
                int nj = j + dj[k];

                if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
                    int weight = grid[ni][nj];
                    if (dist[i][j] + weight < dist[ni][nj]) {
                        dist[ni][nj] = dist[i][j] + weight;
                        if (weight == 0)
                            dq.push_front({ni, nj});
                        else
                            dq.push_back({ni, nj});
                    }
                }
            }
        }
        return dist[m - 1][n - 1] < health;
    }
};