// Last updated: 4/3/2026, 2:00:55 PM
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        // Start searching from the top-right corner of the matrix
        int row = 0, col = matrix[0].size() - 1;
        while (row < matrix.size() && col >= 0) {
            if (matrix[row][col] == target)
                return true;

            // Move Left (decrease column)
            else if (matrix[row][col] > target)
                col--;
            
            // Move Down (increase row)
            else
                row++;
        }
        return false;
    }
};