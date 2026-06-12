// Last updated: 12/6/2026, 11:22:38 pm
1#define pb push_back
2
3class Solution {
4public:
5    int M = 1e9 + 7;
6    int n;
7    int cols;
8
9    unordered_map<int, vector<int>> adj;
10    vector<vector<int>> ancestorTable;
11    vector<int> depth;
12
13    void dfs(int root, int parent) {
14        ancestorTable[root][0] = parent;
15
16        for (int& ngbr : adj[root]) {
17            if (ngbr == parent)
18                continue;
19
20            depth[ngbr] = depth[root] + 1;
21            dfs(ngbr, root);
22        }
23    }
24
25    void buildAncestorTable() {
26        for (int j = 1; j < cols; j++) {
27            for (int node = 0; node < n; node++) {
28                if (ancestorTable[node][j - 1] != -1)
29                    ancestorTable[node][j] =
30                        ancestorTable[ancestorTable[node][j - 1]][j - 1];
31            }
32        }
33    }
34
35    int findLCA(int u, int v) {
36        if (depth[u] < depth[v])
37            swap(u, v);
38
39        int k = depth[u] - depth[v];
40        for (int j = 0; j < cols; j++) {
41            if (k & (1 << j))
42                u = ancestorTable[u][j];
43        }
44
45        if (u == v)
46            return u;
47
48        for (int j = cols - 1; j >= 0; j--) {
49            if (ancestorTable[u][j] == -1)
50                continue;
51
52            if (ancestorTable[u][j] != ancestorTable[v][j]) {
53                u = ancestorTable[u][j];
54                v = ancestorTable[v][j];
55            }
56        }
57
58        return ancestorTable[u][0];
59    }
60
61    vector<int> assignEdgeWeights(vector<vector<int>>& edges,
62                                  vector<vector<int>>& queries) {
63        n = edges.size() + 1;
64        cols = log2(n) + 1;
65
66        for (auto& edge : edges) {
67            int u = edge[0] - 1;
68            int v = edge[1] - 1;
69
70            adj[u].pb(v);
71            adj[v].pb(u);
72        }
73
74        depth.resize(n, 0);
75        ancestorTable.resize(n, vector<int>(cols, -1));
76
77        dfs(0, -1);
78        buildAncestorTable();
79
80        vector<int> pow2(n + 1);
81        pow2[0] = 1;
82        for (int i = 1; i <= n; i++)
83            pow2[i] = (2LL * pow2[i - 1]) % M;
84
85        vector<int> result;
86        for (auto& query : queries) {
87            int u = query[0] - 1;
88            int v = query[1] - 1;
89
90            int lca = findLCA(u, v);
91            int d = depth[u] + depth[v] - 2 * depth[lca];
92
93            if (d == 0)
94                result.pb(0);
95            else
96                result.pb(pow2[d - 1]);
97        }
98        return result;
99    }
100};