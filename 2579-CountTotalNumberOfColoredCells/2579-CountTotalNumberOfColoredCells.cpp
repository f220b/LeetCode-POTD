// Last updated: 9/5/2026, 12:19:20 AM
class Solution {
public:
    long long coloredCells(int n) {
        long long uppertriangle = (long long)n * n;
        long long lowertriangle = (long long)(n - 1) * (n - 1);
        return uppertriangle + lowertriangle;
    }
};