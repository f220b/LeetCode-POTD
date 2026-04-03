// Last updated: 4/3/2026, 1:49:36 PM
class Solution {
public:
    int getMinDiff(set<int>& st) {
        if (st.size() < 2)
            return 0;

        int minDiff = INT_MAX;
        auto it = st.begin();
        auto nextIt = next(it);

        while (nextIt != st.end()) {
            minDiff = min(minDiff, *nextIt - *it);
            it++;
            nextIt++;
        }
        return minDiff;
    }
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> ans(m - k + 1, vector<int>(n - k + 1, 0));
        for (int i = 0; i <= m - k; i++) {
            for (int j = 0; j <= n - k; j++) {

                set<int> subMatrix;
                for (int i1 = i; i1 < i + k; i1++) {
                    for (int j1 = j; j1 < j + k; j1++)
                        subMatrix.insert(grid[i1][j1]);
                }
                ans[i][j] = getMinDiff(subMatrix);
            }
        }
        return ans;
    }
};