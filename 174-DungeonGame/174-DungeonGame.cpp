// Last updated: 4/3/2026, 2:01:39 PM
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();

        vector<int> prev(n, 0);
        vector<int> curr(n, 0);

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (i == m - 1 && j == n - 1)
                    curr[j] = max(1, 1 - dungeon[i][j]);
                else {
                    int down = INT_MAX, right = INT_MAX;
                    if (i + 1 < m)
                        down = prev[j];
                    if (j + 1 < n)
                        right = curr[j + 1];
                    int res = min(down, right) - dungeon[i][j];
                    curr[j] = max(1, res);
                }
            }
            prev = curr;
        }

        return prev[0];
    }
};