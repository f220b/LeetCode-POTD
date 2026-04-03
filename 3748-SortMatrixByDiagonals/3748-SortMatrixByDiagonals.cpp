// Last updated: 4/3/2026, 1:50:11 PM
class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        for (int k = 0; k < n; k++) {
            vector<int> diag;
            for (int i = 0, j = k; i < n && j < n; i++, j++)
                diag.push_back(grid[i][j]);
            if (k == 0)
                sort(diag.rbegin(), diag.rend());
            else
                sort(diag.begin(), diag.end());
            for (int i = 0, j = k, idx = 0; i < n && j < n; i++, j++, idx++)
                grid[i][j] = diag[idx];
        }
        for (int k = 1; k < n; k++) {
            vector<int> diag;
            for (int i = k, j = 0; i < n && j < n; i++, j++)
                diag.push_back(grid[i][j]);
            sort(diag.rbegin(), diag.rend());
            for (int i = k, j = 0, idx = 0; i < n && j < n; i++, j++, idx++)
                grid[i][j] = diag[idx];
        }
        return grid;
    }
};
