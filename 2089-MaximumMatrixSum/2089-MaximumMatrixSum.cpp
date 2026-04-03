// Last updated: 4/3/2026, 1:54:50 PM
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0;
        int countNeg = 0, n = matrix.size(), minNum = abs(matrix[0][0]);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                sum += abs(matrix[i][j]);
                if (matrix[i][j] < 0)
                    countNeg++;
                minNum = min(minNum, abs(matrix[i][j]));
            }
        }
        // -ve count is even -> all values can be converted to +ve
        if (countNeg % 2 == 0)
            return sum;
        // -ve count is odd -> all values but 1 can be converted to +ve
        // So keep the smallest value as -ve
        return sum - (2 * minNum);
    }
};