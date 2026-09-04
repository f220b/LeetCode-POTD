// Last updated: 9/5/2026, 12:19:53 AM
#define pb push_back
class Solution {
public:
    using vi = vector<int>;
    using pp = pair<int, int>;
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pp>> adj(n + 1);
        for (auto i : roads) {
            int a = i[0], b = i[1], dist = i[2];
            adj[a].pb({b, dist});
            adj[b].pb({a, dist});
        }
        vector<int> visited(n + 1, 0);
        queue<int> q;
        q.push(1);
        visited[1] = 1;
        int ans = INT_MAX;

        while (!q.empty()) {
            int city = q.front();
            q.pop();

            for (auto& [neighbour, dist] : adj[city]) {
                ans = min(ans, dist);
                if (!visited[neighbour]) {
                    visited[neighbour] = 1;
                    q.push(neighbour);
                }
            }
        }
        return ans;
    }
};