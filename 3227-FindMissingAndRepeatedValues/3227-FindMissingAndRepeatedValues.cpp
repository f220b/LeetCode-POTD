// Last updated: 4/3/2026, 1:52:07 PM
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid[0].size() * grid.size();
        long long sn = (n * (n + 1)) / 2;
        long long s2n = ((long long)n * (n + 1) * (2 * n + 1)) / 6;
        long long s = 0, s2 = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                s += (long long)grid[i][j];
                s2 += (long long)grid[i][j] * grid[i][j];
            }
        }
        long long diff = s - sn;
        long long sum = (s2 - s2n) / diff;
        int repeating = (int)(diff + sum) / 2;
        int missing = (int)(sum - diff) / 2;
        return {repeating, missing};
    }
};