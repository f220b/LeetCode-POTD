// Last updated: 4/3/2026, 1:53:40 PM
class Solution {
public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> subtree_xor(n), tin(n), tout(n);
        int timer = 0;

        function<void(int, int)> dfs = [&](int u, int p) {
            tin[u] = timer++;
            subtree_xor[u] = nums[u];
            for (int v : adj[u]) {
                if (v != p) {
                    dfs(v, u);
                    subtree_xor[u] ^= subtree_xor[v];
                }
            }
            tout[u] = timer++;
        };

        dfs(0, -1);

        int total_xor = subtree_xor[0];
        int min_score = INT_MAX;

        auto is_ancestor = [&](int u, int v) {
            return tin[u] <= tin[v] && tout[u] >= tout[v];
        };

        for (int i = 1; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int xi = subtree_xor[i], xj = subtree_xor[j];
                int a, b, c;

                if (is_ancestor(i, j)) {
                    a = xj;
                    b = xi ^ xj;
                    c = total_xor ^ xi;
                } else if (is_ancestor(j, i)) {
                    a = xi;
                    b = xj ^ xi;
                    c = total_xor ^ xj;
                } else {
                    a = xi;
                    b = xj;
                    c = total_xor ^ xi ^ xj;
                }

                int score = max({a, b, c}) - min({a, b, c});
                min_score = min(min_score, score);
            }
        }

        return min_score;
    }
};
