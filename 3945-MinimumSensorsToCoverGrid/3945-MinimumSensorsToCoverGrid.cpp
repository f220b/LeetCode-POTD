// Last updated: 4/3/2026, 1:49:25 PM
class Solution {
public:
    int minSensors(int n, int m, int k) {
        int cover = 2 * k + 1;
        int rows = (n + cover - 1) / cover;
        int cols = (m + cover - 1) / cover;
        return rows * cols;
    }
};