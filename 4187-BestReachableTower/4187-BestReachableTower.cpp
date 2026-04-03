// Last updated: 4/3/2026, 1:48:48 PM
class Solution {
public:
    vector<int> bestTower(vector<vector<int>>& towers, vector<int>& center,
                          int radius) {
        int cx = center[0], cy = center[1];
        vector<int> ans = {-1, -1};
        int bestQ = -1;

        for (int i = 0; i < towers.size(); i++) {
            int x = towers[i][0], y = towers[i][1], q = towers[i][2];
            // Manhattan Distance
            if ((abs(x - cx) + abs(y - cy)) <= radius) {
                // Better Quality Factor
                if (q > bestQ ||
                    (q == bestQ && (x < ans[0] || x == ans[0] && y < ans[1]))) {
                    bestQ = q;
                    ans = {x, y};
                }
            }
        }
        return ans;
    }
};