// Last updated: 4/3/2026, 1:56:07 PM
class Solution {
public:
    int minCost(int n, vector<int>& cuts) {

        // coordinate compression
        vector<int> pos = cuts;
        pos.push_back(0);
        pos.push_back(n);
        sort(pos.begin(), pos.end());

        int m = pos.size();
        vector<vector<int>> dp(m, vector<int>(m, 0));

        for (int i = m - 1; i >= 0; i--) {
            for (int j = i + 1; j < m; j++) {
                int mini = INT_MAX;

                for (int cut : cuts) {
                    if (cut > pos[i] && cut < pos[j]) {
                        int k = lower_bound(pos.begin(), pos.end(), cut) - pos.begin();
                        int cost = (pos[j] - pos[i]) + dp[i][k] + dp[k][j];
                        mini = min(mini, cost);
                    }
                }
                dp[i][j] = (mini == INT_MAX ? 0 : mini);
            }
        }
        return dp[0][m - 1];
    }
};
