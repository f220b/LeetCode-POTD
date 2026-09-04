// Last updated: 9/5/2026, 12:07:35 AM
class Solution {
public:
    int minSensors(int n, int m, int k) {
        int cover = 2 * k + 1;
        int rows = (n + cover - 1) / cover;
        int cols = (m + cover - 1) / cover;
        return rows * cols;
    }
};