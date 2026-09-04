// Last updated: 9/5/2026, 12:33:48 AM
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int b = 0, a = 0, l = 0, o = 0, n = 0;
        for (char ch : text) {
            if (ch == 'b')
                b++;
            else if (ch == 'a')
                a++;
            else if (ch == 'l')
                l++;
            else if (ch == 'o')
                o++;
            else if (ch == 'n')
                n++;
        }
        if (b == 0 || a == 0 || l == 0 || o == 0 || n == 0)
            return 0;

        return min({b, a, l >> 1, o >> 1, n});
    }
};