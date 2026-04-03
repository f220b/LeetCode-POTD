// Last updated: 4/3/2026, 1:49:49 PM
class Solution {
public:
    int findClosest(int x, int y, int z) {
        if(abs(x - z) == abs(y - z))
            return 0;
        return (abs(x - z) < abs(y - z)) ? 1 : 2;
    }
};