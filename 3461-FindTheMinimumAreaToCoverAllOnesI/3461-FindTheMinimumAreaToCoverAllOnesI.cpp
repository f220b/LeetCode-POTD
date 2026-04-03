// Last updated: 4/3/2026, 1:51:21 PM
class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int top = -1, bottom = -1, left = -1, right = -1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    if (top == -1)                      // Top most 1
                        top = i;
                    if (bottom < i)                     // Bottom most 1
                        bottom = i;
                    if (left == -1 || left > j)         // Most left 1
                        left = j;
                    if (right < j)       // Right most 1
                        right = j;
                }
            }
        }
        int length = right - left + 1;
        int breadth = bottom - top + 1;
        return length * breadth;
    }
};