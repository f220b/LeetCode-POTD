// Last updated: 4/3/2026, 2:02:59 PM
class Solution {
public:
    int rows, cols;
    int maximumArea(vector<int>& temp) {
        stack<int> st;
        int area = 0;
        for (int i = 0; i <= cols; i++) {
            while (!st.empty() && (i == cols || temp[i] <= temp[st.top()])) {
                int height = temp[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                area = max(area, height * width);
            }
            st.push(i);
        }
        return area;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        rows = matrix.size();
        cols = matrix[0].size();

        vector<int> temp(cols, 0);
        int maxArea = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                temp[j] = matrix[i][j] == '0' ? 0 : temp[j] + 1;
            }
            maxArea = max(maxArea, maximumArea(temp));
        }
        return maxArea;
    }
};