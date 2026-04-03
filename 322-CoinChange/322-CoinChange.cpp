// Last updated: 4/3/2026, 2:00:35 PM
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> prev(amount + 1, 0);
        for (int left = 0; left <= amount; left++) {
            if (left % coins[0] == 0)
                prev[left] = left / coins[0];
            else
                prev[left] = 1e9;
        }
        vector<int> curr(amount + 1, 0);
        for (int i = 1; i < n; i++) {
            for (int left = 1; left <= amount; left++) {
                int notPick = prev[left];
                int pick = 1e9;
                if (coins[i] <= left)
                    pick = 1 + curr[left - coins[i]];

                curr[left] = min(pick, notPick);
            }
            prev = curr;
        }
        int ans = prev[amount];
        return (ans >= 1e9) ? -1 : ans;
    }
};