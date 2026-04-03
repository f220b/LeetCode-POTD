// Last updated: 4/3/2026, 1:58:19 PM
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> prev = matrix[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            vector<int> curr(n, 0);
            for (int j = 0; j < n; j++) {
                int down = matrix[i][j] + prev[j];
                int downLeft = (j > 0) ? (matrix[i][j] + prev[j - 1]) : INT_MAX;
                int downRight =
                    (j < n - 1) ? (matrix[i][j] + prev[j + 1]) : INT_MAX;

                curr[j] = min({down, downLeft, downRight});
            }
            prev = curr;
        }
        int minSum = INT_MAX;
        for (int j = 0; j < n; j++)
            minSum = min(minSum, prev[j]);
        return minSum;
    }
};
