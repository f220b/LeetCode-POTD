// Last updated: 4/3/2026, 1:56:21 PM
class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> heights(n, 0);
        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1)
                    heights[j]++;
                else
                    heights[j] = 0;
            }

            stack<int> st;
            vector<int> dp(n, 0);

            for (int j = 0; j < n; j++) {
                while (!st.empty() && heights[st.top()] >= heights[j])
                    st.pop();

                if (!st.empty()) {
                    int prev = st.top();
                    dp[j] = dp[prev] + heights[j] * (j - prev);
                } else {
                    dp[j] = heights[j] * (j + 1);
                }

                st.push(j);
                ans += dp[j];
            }
        }

        return ans;
    }
};
