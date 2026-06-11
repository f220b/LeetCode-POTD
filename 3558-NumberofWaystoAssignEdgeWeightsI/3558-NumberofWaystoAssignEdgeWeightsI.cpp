// Last updated: 11/6/2026, 8:48:59 pm
1class Solution {
2public:
3    const int MOD = 1e9 + 7;
4    int power(long long a, long long b) {
5        long long ans = 1;
6        a %= MOD;
7        while (b > 0) {
8            if (b & 1)
9                ans = (ans * a) % MOD;
10            a = (a * a) % MOD;
11            b >>= 1;
12        }
13        return (int)ans;
14    }
15    int dfs(int node, int per, vector<vector<int>>& adj) {
16        if (adj[node].size() == 0)
17            return 0;
18            
19        int ans = 0;
20        for (auto& it : adj[node]) {
21            if (it != per)
22                ans = max(ans, 1 + dfs(it, node, adj));
23        }
24        return ans;
25    }
26    int assignEdgeWeights(vector<vector<int>>& edges) {
27        int n = edges.size() + 2;
28        vector<vector<int>> adj(n);
29        for (auto& edge : edges) {
30            int u = edge[0], v = edge[1];
31            adj[u].push_back(v);
32            adj[v].push_back(u);
33        }
34        int depth = dfs(1, -1, adj);
35        return power(2, depth - 1);
36    }
37};