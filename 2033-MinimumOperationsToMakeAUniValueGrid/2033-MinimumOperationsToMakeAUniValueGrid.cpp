// Last updated: 9/5/2026, 12:24:39 AM
class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int remainder = grid[0][0] % x;
        vector<int> arr;
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] % x != remainder)
                    return -1;
                arr.push_back(grid[i][j]);
            }
        }
        sort(arr.begin(), arr.end());
        n = arr.size();
        int median = n / 2;
        int steps = 0;
        for (int i = 0; i < n; i++) {
            steps += abs(arr[i] - arr[median]) / x;
        }
        return steps;
    }
};