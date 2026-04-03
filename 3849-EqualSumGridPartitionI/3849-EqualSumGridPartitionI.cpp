// Last updated: 4/3/2026, 1:49:44 PM
class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        long long total = 0;

        vector<long long> rSum(m, 0);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                rSum[i] += grid[i][j];
            }
            total += rSum[i];
        }

        if (total % 2 != 0)
            return false;
        long long target = total / 2;

        long long currentR = 0;
        for (int i = 0; i < m - 1; ++i) {
            currentR += rSum[i];
            if (currentR == target)
                return true;
        }

        long long currentC = 0;
        for (int j = 0; j < n - 1; ++j) {
            long long colVal = 0;
            for (int i = 0; i < m; ++i) {
                colVal += grid[i][j];
            }
            currentC += colVal;
            if (currentC == target)
                return true;
        }

        return false;
    }
};