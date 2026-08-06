// Last updated: 8/6/2026, 1:21:33 PM
class Solution {
public:
    bool judgeCircle(string moves) {
        int i = 0, j = 0;
        for (char ch : moves) {
            if (ch == 'U')
                i--;
            else if (ch == 'D')
                i++;
            else if (ch == 'R')
                j++;
            else
                j--;
        }
        return (i == 0 && j == 0);
    }
};