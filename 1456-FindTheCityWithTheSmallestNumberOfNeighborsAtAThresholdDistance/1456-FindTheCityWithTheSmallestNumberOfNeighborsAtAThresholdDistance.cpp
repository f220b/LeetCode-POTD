// Last updated: 4/3/2026, 1:57:01 PM
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> matrix(n, vector<int>(n, 1e9));

        for (int i = 0; i < n; i++)
            matrix[i][i] = 0;
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            matrix[u][v] = w;
            matrix[v][u] = w;
        }

        for (int via = 0; via < n; via++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    matrix[i][j] =
                        min(matrix[i][j], matrix[i][via] + matrix[via][j]);
                }
            }
        }

        int ansCity = -1;
        int minReachable = INT_MAX;
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (i != j && matrix[i][j] <= distanceThreshold)
                    count++;
            }
            if (count < minReachable ||
                (count == minReachable && i > ansCity)) {
                minReachable = count;
                ansCity = i;
            }
        }

        return ansCity;
    }
};
