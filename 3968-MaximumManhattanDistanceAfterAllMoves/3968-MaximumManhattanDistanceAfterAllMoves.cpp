// Last updated: 9/5/2026, 12:00:53 AM
class Solution {
public:
    int maxDistance(string moves) {
        int x = 0, y = 0, us = 0;
        for (char ch : moves) {
            if (ch == 'U')
                y++;
            else if (ch == 'D')
                y--;
            else if (ch == 'L')
                x--;
            else if (ch == 'R')
                x++;
            else
                us++;
        }
        return abs(x) + abs(y) + us;
    }
};