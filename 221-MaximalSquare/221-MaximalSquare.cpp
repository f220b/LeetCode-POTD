// Last updated: 4/3/2026, 2:01:15 PM
class Solution {
public:
    int maximumArea(vector<int>& heights, int n) {
        stack<int> st;
        int maxArea = 0;

        for (int i = 0; i <= n; i++) {
            while (!st.empty() && (i == n || heights[st.top()] >= heights[i])) {
                int height = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                int side = min(height, width);
                maxArea = max(maxArea, side * side);
            }
            st.push(i);
        }
        return maxArea;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> heights(n, 0);
        int maxArea = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                heights[j] = matrix[i][j] == '1' ? heights[j] + 1 : 0;
            }
            maxArea = max(maxArea, maximumArea(heights, n));
        }
        return maxArea;
    }
};