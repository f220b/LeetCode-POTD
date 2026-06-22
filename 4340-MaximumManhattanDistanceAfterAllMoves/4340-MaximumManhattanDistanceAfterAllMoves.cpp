// Last updated: 22/6/2026, 7:41:24 pm
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