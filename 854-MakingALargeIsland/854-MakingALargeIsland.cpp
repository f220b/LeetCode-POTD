// Last updated: 4/3/2026, 1:58:43 PM
class Solution {
public:
    int n;
    vector<vector<int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    
    int dfs(vector<vector<int>>& grid, int r, int c, int index) {
        if (r < 0 || c < 0 || r >= n || c >= n || grid[r][c] != 1) return 0;
        grid[r][c] = index;
        int size = 1;
        for (auto& dir : directions) {
            size += dfs(grid, r + dir[0], c + dir[1], index);
        }
        return size;
    }
    
    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size();
        unordered_map<int, int> islandSize;
        int index = 2, maxIsland = 0;
        
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 1) {
                    int size = dfs(grid, r, c, index);
                    islandSize[index++] = size;
                    maxIsland = max(maxIsland, size);
                }
            }
        }
        
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 0) {
                    unordered_set<int> seenIslands;
                    int newSize = 1;
                    for (auto& dir : directions) {
                        int nr = r + dir[0], nc = c + dir[1];
                        if (nr >= 0 && nc >= 0 && nr < n && nc < n && grid[nr][nc] > 1) {
                            seenIslands.insert(grid[nr][nc]);
                        }
                    }
                    for (int id : seenIslands) {
                        newSize += islandSize[id];
                    }
                    maxIsland = max(maxIsland, newSize);
                }
            }
        }
        
        return maxIsland;
    }
};
