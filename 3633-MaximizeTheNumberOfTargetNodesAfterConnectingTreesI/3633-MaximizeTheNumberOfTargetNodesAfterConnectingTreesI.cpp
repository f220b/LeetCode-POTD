// Last updated: 4/3/2026, 1:50:41 PM
class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1,
                               vector<vector<int>>& edges2, int k) {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;

        // Build adjacency lists for both trees
        vector<vector<int>> tree1(n);
        for (const auto& edge : edges1) {
            int u = edge[0];
            int v = edge[1];
            tree1[u].push_back(v);
            tree1[v].push_back(u);
        }

        vector<vector<int>> tree2(m);
        for (const auto& edge : edges2) {
            int u = edge[0];
            int v = edge[1];
            tree2[u].push_back(v);
            tree2[v].push_back(u);
        }

        // Precompute distances for all nodes in tree2
        vector<vector<int>> dist2(m, vector<int>(m, -1));
        for (int i = 0; i < m; ++i) {
            queue<int> q;
            q.push(i);
            dist2[i][i] = 0;
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (int v : tree2[u]) {
                    if (dist2[i][v] == -1) {
                        dist2[i][v] = dist2[i][u] + 1;
                        q.push(v);
                    }
                }
            }
        }

        // For each node in tree2, find the number of nodes within distance k -
        // 1 (since one edge is used to connect)
        vector<int> max_add(m, 0);
        for (int j = 0; j < m; ++j) {
            int cnt = 0;
            for (int l = 0; l < m; ++l) {
                if (dist2[j][l] <= k - 1) {
                    cnt++;
                }
            }
            max_add[j] = cnt;
        }

        // Precompute distances for all nodes in tree1
        vector<vector<int>> dist1(n, vector<int>(n, -1));
        for (int i = 0; i < n; ++i) {
            queue<int> q;
            q.push(i);
            dist1[i][i] = 0;
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (int v : tree1[u]) {
                    if (dist1[i][v] == -1) {
                        dist1[i][v] = dist1[i][u] + 1;
                        q.push(v);
                    }
                }
            }
        }

        vector<int> answer(n, 0);
        for (int i = 0; i < n; ++i) {
            // Count nodes in tree1 within distance k of i
            int cnt1 = 0;
            for (int u = 0; u < n; ++u) {
                if (dist1[i][u] <= k) {
                    cnt1++;
                }
            }

            // The best possible addition is the maximum max_add[j] over all j
            // in tree2
            int best_add = 0;
            if (k >= 0) {
                best_add = *max_element(max_add.begin(), max_add.end());
            }

            answer[i] = cnt1 + best_add;
        }

        return answer;
    }
};