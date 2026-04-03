// Last updated: 4/3/2026, 1:57:15 PM
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();    // Number of rows
        int n = grid[0].size(); // Number of columns

        vector<int> rowCount(m, 0); // Count of servers in each row
        vector<int> colCount(n, 0); // Count of servers in each column

        // First pass: Count servers in each row and column
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    rowCount[i]++;
                    colCount[j]++;
                }
            }
        }

        // Second pass: Count servers that can communicate
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && (rowCount[i] > 1 || colCount[j] > 1)) {
                    count++;
                }
            }
        }

        return count;
    }
};
