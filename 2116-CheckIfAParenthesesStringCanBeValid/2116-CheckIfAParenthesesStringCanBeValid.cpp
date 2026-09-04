// Last updated: 9/5/2026, 12:23:45 AM
class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.length();
        if (n % 2 != 0)
            return false;

        int opening = 0, closing = 0, changeable = 0;
        for (int i = 0; i < n; i++) {
            if (locked[i] == '0') {
                changeable++;
            } else if (s[i] == '(') {
                opening++;
            } else {
                closing++;
            }
            if (changeable < (closing - opening))
                return false;
        }

        opening = 0, closing = 0, changeable = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (locked[i] == '0') {
                changeable++;
            } else if (s[i] == '(') {
                opening++;
            } else {
                closing++;
            }
            if (changeable < (opening - closing))
                return false;
        }

        return true;
    }
};
