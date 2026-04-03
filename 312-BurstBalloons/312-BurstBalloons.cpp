// Last updated: 4/3/2026, 2:00:39 PM
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();

        vector<int> temp;
        temp.push_back(1);
        temp.insert(temp.end(), nums.begin(), nums.end());
        temp.push_back(1);

        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        for (int i = n; i >= 1; i--) {
            for (int j = i; j <= n; j++) {
                int maxCost = INT_MIN;
                for (int ind = i; ind <= j; ind++) {
                    int cost = (temp[i - 1] * temp[ind] * temp[j + 1]) +
                               dp[i][ind - 1] + dp[ind + 1][j];
                    maxCost = max(maxCost, cost);
                }
                dp[i][j] = maxCost;
            }
        }
        return dp[1][n];
    }
};