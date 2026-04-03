// Last updated: 4/3/2026, 1:56:29 PM
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<int>> prev(cols, vector<int>(cols, 0));

        for (int j1 = 0; j1 < cols; j1++) {
            for (int j2 = 0; j2 < cols; j2++) {
                if (j1 == j2)
                    prev[j1][j2] = grid[rows - 1][j1];
                else
                    prev[j1][j2] = grid[rows - 1][j1] + grid[rows - 1][j2];
            }
        }
        for (int i = rows - 2; i >= 0; i--) {
            vector<vector<int>> curr(cols, vector<int>(cols, 0));
            for (int j1 = 0; j1 < cols; j1++) {
                for (int j2 = 0; j2 < cols; j2++) {
                    int maxi = INT_MIN;
                    vector<int> dj = {-1, 0, 1};
                    for (int k1 = 0; k1 < 3; k1++) {
                        for (int k2 = 0; k2 < 3; k2++) {
                            int nj1 = j1 + dj[k1];
                            int nj2 = j2 + dj[k2];
                            if (nj1 >= 0 && nj1 < cols && nj2 >= 0 &&
                                nj2 < cols) {
                                if (j1 == j2)
                                    maxi =
                                        max(maxi, grid[i][j1] + prev[nj1][nj2]);
                                else
                                    maxi = max(maxi, grid[i][j1] + grid[i][j2] +
                                                         prev[nj1][nj2]);
                            }
                        }
                    }
                    curr[j1][j2] = maxi;
                }
            }
            prev = curr;
        }
        return prev[0][cols - 1];
    }
};