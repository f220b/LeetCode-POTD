// Last updated: 4/3/2026, 1:54:41 PM
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
