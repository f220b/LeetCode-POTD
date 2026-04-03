// Last updated: 4/3/2026, 1:52:23 PM
class Solution {
public:
    long long dfs(int node, int parent, vector<vector<int>>& adj,
                  vector<int>& values, int k, int& ans) {
        long long sum = values[node];

        for (int child : adj[node]) {
            if (child == parent)
                continue;
            sum += dfs(child, node, adj, values, k, ans);
        }

        if (sum % k == 0) {
            ans++;
            return 0;
        }
        return sum;
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges,
                                vector<int>& values, int k) {
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int ans = 0;
        dfs(0, -1, adj, values, k, ans);
        return ans;
    }
};
