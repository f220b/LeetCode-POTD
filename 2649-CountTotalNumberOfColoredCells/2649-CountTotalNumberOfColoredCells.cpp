// Last updated: 4/3/2026, 1:52:59 PM
class Solution {
public:
    long long coloredCells(int n) {
        long long uppertriangle = (long long)n * n;
        long long lowertriangle = (long long)(n - 1) * (n - 1);
        return uppertriangle + lowertriangle;
    }
};