// Last updated: 4/3/2026, 1:59:38 PM
class Solution {
public:
    vector<int> visited;
    vector<vector<int>> adj;
    void dfs(int currCity) {
        // Mark the current city as visited
        visited[currCity] = 1;
        for (int nextCity : adj[currCity]) {
            // If the neighbour city is not visited,
            // Visit that city next
            if (visited[nextCity] == 0)
                dfs(nextCity);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        adj.resize(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // City i and j are connected
                // Don't need to connect j and i
                // because it will happen further in the loop
                if (isConnected[i][j] == 1)
                    adj[i].push_back(j);
            }
        }
        // Keep track of visited cities
        visited.resize(n, 0);
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (visited[i] == 1)
                continue;
            count++;
            dfs(i);
        }
        return count;
    }
};