// Last updated: 4/3/2026, 2:02:28 PM
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> prev = triangle[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            vector<int> curr(n, 0);
            for (int j = i; j >= 0; j--) {
                int bottom = triangle[i][j] + prev[j];
                int bottomRight = triangle[i][j] + prev[j + 1];

                curr[j] = min(bottom, bottomRight);
            }
            prev = curr;
        }
        return prev[0];
    }
};