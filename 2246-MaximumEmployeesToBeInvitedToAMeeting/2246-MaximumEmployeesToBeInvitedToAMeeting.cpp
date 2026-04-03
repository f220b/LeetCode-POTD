// Last updated: 4/3/2026, 1:54:15 PM
class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        vector<int> indegree(n, 0), dp(n, 1);
        vector<vector<int>> revGraph(n);
        
        // Calculate indegree and build reverse graph
        for (int i = 0; i < n; i++) {
            indegree[favorite[i]]++;
            revGraph[favorite[i]].push_back(i);
        }

        queue<int> q;
        for (int i = 0; i < n; i++)
            if (indegree[i] == 0) q.push(i);

        // Process chains (remove leaf nodes and track chain length)
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            int v = favorite[u];
            dp[v] = max(dp[v], dp[u] + 1);
            if (--indegree[v] == 0) q.push(v);
        }

        int maxCycleSize = 0, maxChainSum = 0;
        vector<bool> visited(n, false);

        // Process cycles and remaining chains
        for (int i = 0; i < n; i++) {
            if (indegree[i] > 0) {  // Cycle found
                int cycleSize = 0, x = i;
                while (!visited[x]) {
                    visited[x] = true;
                    cycleSize++;
                    x = favorite[x];
                }
                if (cycleSize == 2) {
                    maxChainSum += dp[i] + dp[favorite[i]];
                } else {
                    maxCycleSize = max(maxCycleSize, cycleSize);
                }
            }
        }

        return max(maxCycleSize, maxChainSum);
    }
};
