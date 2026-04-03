// Last updated: 4/3/2026, 1:59:44 PM
class Solution {
public:
    int solve(int ind, int currAmount, vector<int>& coins,
              vector<vector<int>>& dp) {
        if (ind == 0) {
            if ((currAmount % coins[ind]) == 0)
                return 1;
            return 0;
        }
        if (dp[ind][currAmount] != -1)
            return dp[ind][currAmount];
        int pick = 0;
        if (coins[ind] <= currAmount)
            pick = solve(ind, currAmount - coins[ind], coins, dp);
        int notPick = solve(ind - 1, currAmount, coins, dp);

        return dp[ind][currAmount] = (pick + notPick);
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        return solve(n - 1, amount, coins, dp);
    }
};