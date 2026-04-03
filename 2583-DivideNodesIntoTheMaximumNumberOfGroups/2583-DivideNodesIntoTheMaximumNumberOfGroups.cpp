// Last updated: 4/3/2026, 1:53:07 PM
class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n + 1);
        
        // Build adjacency list
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> color(n + 1, 0); // 0: unvisited, 1: color1, -1: color2
        vector<bool> visited(n + 1, false);
        int maxGroups = 0;

        // Function to check bipartiteness and get all nodes in the component
        auto isBipartite = [&](int start, vector<int>& component) -> bool {
            queue<int> q;
            q.push(start);
            color[start] = 1;
            component.push_back(start);

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (int neighbor : adj[node]) {
                    if (color[neighbor] == 0) {
                        color[neighbor] = -color[node];
                        q.push(neighbor);
                        component.push_back(neighbor);
                    } else if (color[neighbor] == color[node]) {
                        return false; // Odd-length cycle detected
                    }
                }
            }
            return true;
        };

        // BFS to calculate the maximum depth from any node
        auto bfsMaxDepth = [&](int start) -> int {
            queue<int> q;
            vector<int> dist(n + 1, -1);
            q.push(start);
            dist[start] = 0;
            int maxDepth = 0;

            while (!q.empty()) {
                int node = q.front();
                q.pop();
                maxDepth = max(maxDepth, dist[node]);

                for (int neighbor : adj[node]) {
                    if (dist[neighbor] == -1) {
                        dist[neighbor] = dist[node] + 1;
                        q.push(neighbor);
                    }
                }
            }
            return maxDepth + 1;
        };

        // Process each connected component
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                vector<int> component;
                if (!isBipartite(i, component)) {
                    return -1;
                }

                // Mark component nodes as visited
                for (int node : component) visited[node] = true;

                // Find the best starting node in the component for max depth
                int maxDepth = 0;
                for (int node : component) {
                    maxDepth = max(maxDepth, bfsMaxDepth(node));
                }
                maxGroups += maxDepth;
            }
        }

        return maxGroups;
    }
};
