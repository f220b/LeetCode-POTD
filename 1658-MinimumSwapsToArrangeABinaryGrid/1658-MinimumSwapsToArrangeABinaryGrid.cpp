// Last updated: 4/3/2026, 1:56:10 PM
class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> endZeroes(n);
        for (int i = 0; i < n; i++) {
            int count = 0, j = n - 1;
            while (j >= 0 && grid[i][j] == 0) {
                count++;
                j--;
            }
            endZeroes[i] = count;
        }
        int steps = 0;
        for (int i = 0; i < n; i++) {
            int need = n - i - 1, j = i;
            while (j < n && endZeroes[j] < need) {
                j++;
            }
            if (j == n)
                return -1;
            steps += (j - i);
            while (j > i) {
                swap(endZeroes[j], endZeroes[j - 1]);
                j--;
            }
        }
        return steps;
    }
};