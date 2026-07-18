// Last updated: 7/18/2026, 11:56:23 PM
#define ff first
#define ss second
class Solution {
public:
    using pp = pair<int, int>;
    using vi = vector<int>;
    using vb = vector<bool>;
    vi di = {0, 0, -1, 1};
    vi dj = {-1, 1, 0, 0};
    int n;

    bool isValid(int i, int j) { return i >= 0 && i < n && j >= 0 && j < n; }
    void bfs(vector<vi>& grid, vector<vi>& score) {
        queue<pp> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    score[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            int i = t.ff, j = t.ss;
            int s = score[i][j];

            for (int x = 0; x < 4; x++) {
                int newI = i + di[x];
                int newJ = j + dj[x];

                if (isValid(newI, newJ) && score[newI][newJ] > 1 + s) {
                    score[newI][newJ] = 1 + s;
                    q.push({newI, newJ});
                }
            }
        }
    }

    int maximumSafenessFactor(vector<vi>& grid) {
        n = grid.size();
        if (grid[0][0] || grid[n - 1][n - 1])
            return 0;

        vector<vi> score(n, vi(n, INT_MAX));
        bfs(grid, score);
        vector<vb> vis(n, vb(n, false));

        priority_queue<pair<int, pp>> pq;
        pq.push({score[0][0], {0, 0}});

        while (!pq.empty()) {
            auto temp = pq.top().ss;
            auto safe = pq.top().ff;
            pq.pop();

            if (temp.ff == n - 1 && temp.ss == n - 1)
                return safe;

            vis[temp.ff][temp.ss] = true;
            for (int i = 0; i < 4; i++) {
                int newI = temp.ff + di[i];
                int newJ = temp.ss + dj[i];

                if (isValid(newI, newJ) && !vis[newI][newJ]) {
                    int s = min(safe, score[newI][newJ]);
                    pq.push({s, {newI, newJ}});
                    vis[newI][newJ] = true;
                }
            }
        }

        return -1;
    }
};