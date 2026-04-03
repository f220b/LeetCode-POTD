// Last updated: 4/3/2026, 1:58:22 PM
class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<int> visited(n * n + 1, 0);
        queue<pair<int, int>> q; // {square, moves}
        q.push({1, 0});
        visited[1] = 1;

        auto getCoordinates = [&](int num) {
            int r = (num - 1) / n;
            int c = (num - 1) % n;
            if (r % 2 == 1)
                c = n - 1 - c;
            return make_pair(n - 1 - r, c);
        };

        while (!q.empty()) {
            auto [curr, moves] = q.front();
            q.pop();
            if (curr == n * n)
                return moves;

            for (int i = 1; i <= 6 && curr + i <= n * n; ++i) {
                int next = curr + i;
                auto [r, c] = getCoordinates(next);
                if (board[r][c] != -1)
                    next = board[r][c];
                if (!visited[next]) {
                    visited[next] = 1;
                    q.push({next, moves + 1});
                }
            }
        }
        return -1;
    }
};
