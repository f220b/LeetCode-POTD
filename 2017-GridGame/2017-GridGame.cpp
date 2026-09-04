// Last updated: 9/5/2026, 12:24:52 AM
class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long topSum = 0;
        int n = grid[0].size();

        for (int i = 0; i < n; i++) {
            topSum += grid[0][i];
        }

        long long minSum = LLONG_MAX;
        long long bottomSum = 0;
        
        for (int i = 0; i < n; i++) {
            topSum -= grid[0][i];
            minSum = min(minSum, max(topSum, bottomSum));
            bottomSum += grid[1][i];
        }
        return minSum;
    }
};
