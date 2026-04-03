// Last updated: 4/3/2026, 1:52:44 PM
using namespace std;

class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int maxFish = 0;

        // Helper function to perform DFS
        function<int(int, int)> dfs = [&](int r, int c) {
            // Boundary and condition check
            if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == 0) 
                return 0;

            // Collect fish and mark as visited
            int fish = grid[r][c];
            grid[r][c] = 0;

            // Explore all 4 directions
            fish += dfs(r + 1, c); // Down
            fish += dfs(r - 1, c); // Up
            fish += dfs(r, c + 1); // Right
            fish += dfs(r, c - 1); // Left

            return fish;
        };

        // Iterate through the grid
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) {
                    // Perform DFS and update maxFish
                    maxFish = max(maxFish, dfs(i, j));
                }
            }
        }

        return maxFish;
    }
};
