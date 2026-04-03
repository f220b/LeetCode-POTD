// Last updated: 4/3/2026, 2:03:41 PM
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // Time Complexity: O(m*n)
        // Space Complexity: O(n)
        int left = 0, right = matrix[0].size() - 1;
        int top = 0, bottom = matrix.size() - 1;
        vector<int> ans;
        while (left <= right && top <= bottom) {
            // Left to Right
            for (int i = left; i <= right; i++) {
                ans.push_back(matrix[top][i]);
            }
            top++;
            // Top to Bottom
            for (int i = top; i <= bottom; i++) {
                ans.push_back(matrix[i][right]);
            }
            right--;
            if (top <= bottom) {
                // Right to Left
                for (int i = right; i >= left; i--)
                    ans.push_back(matrix[bottom][i]);
                bottom--;
            }
            if (left <= right) {
                // Bottom to Top
                for (int i = bottom; i >= top; i--)
                    ans.push_back(matrix[i][left]);
                left++;
            }
        }
        return ans;
    }
};